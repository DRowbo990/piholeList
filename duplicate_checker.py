#!/usr/bin/env python3

import requests
import re
from urllib.parse import urlparse

# ==========================
# Configuration
# ==========================

MY_LIST_URL = "https://raw.githubusercontent.com/DRowbo990/piholeList/refs/heads/master/list.txt"

COMPARE_LISTS = [
    "https://raw.githubusercontent.com/StevenBlack/hosts/master/hosts",
    "https://raw.githubusercontent.com/Perflyst/PiHoleBlocklist/master/SmartTV.txt",
    "https://raw.githubusercontent.com/hagezi/dns-blocklists/refs/heads/main/domains/native.amazon.txt",
    "https://cdn.jsdelivr.net/gh/hagezi/dns-blocklists@latest/adblock/native.tiktok.extended.txt",
    "https://www.github.developerdan.com/hosts/lists/facebook-extended.txt",
    "https://raw.githubusercontent.com/anudeepND/blacklist/master/facebook.txt",
    "https://cdn.jsdelivr.net/gh/hagezi/dns-blocklists@latest/adblock/native.winoffice.txt",
    "https://cdn.jsdelivr.net/gh/hagezi/dns-blocklists@latest/adblock/gambling.txt",
    "https://cdn.jsdelivr.net/gh/hagezi/dns-blocklists@latest/adblock/nsfw.txt",
    "https://raw.githubusercontent.com/lightswitch05/hosts/refs/heads/master/docs/lists/facebook-extended.txt",
    "https://cdn.jsdelivr.net/gh/hagezi/dns-blocklists@latest/adblock/social.txt",
]

OUTPUT_FILE = "cleaned_blocklist.txt"

# ==========================


DOMAIN_REGEX = re.compile(r"^(?:[a-zA-Z0-9-]+\.)+[a-zA-Z]{2,}$")


def download(url):
    print(f"Downloading {url}")
    r = requests.get(url, timeout=60)
    r.raise_for_status()
    return r.text.splitlines()


def extract_domain(line):
    """
    Attempts to extract a domain from several common blocklist formats.
    Returns None if the line doesn't contain a usable domain.
    """

    line = line.strip()

    if not line:
        return None

    if line.startswith(("!", "#", "//")):
        return None

    # Remove inline comments
    line = line.split("#")[0].strip()

    # Hosts format
    if line.startswith(("0.0.0.0", "127.0.0.1", "::1")):
        parts = line.split()
        if len(parts) >= 2:
            return parts[1].lower()

    # AdGuard/uBlock format
    if line.startswith("||"):
        domain = line[2:]
        domain = domain.split("^")[0]
        domain = domain.split("/")[0]
        return domain.lower()

    # URL
    if line.startswith(("http://", "https://")):
        try:
            return urlparse(line).hostname.lower()
        except Exception:
            return None

    # Plain domain
    if DOMAIN_REGEX.match(line):
        return line.lower()

    return None


def load_domains(url):
    domains = set()

    for line in download(url):
        domain = extract_domain(line)
        if domain:
            domains.add(domain)

    print(f"  Loaded {len(domains):,} domains")
    return domains


def main():

    print("\nLoading your list...")
    my_domains = load_domains(MY_LIST_URL)

    print("\nLoading comparison lists...")
    comparison = set()

    for url in COMPARE_LISTS:
        comparison |= load_domains(url)

    print(f"\nTotal comparison domains: {len(comparison):,}")

    removed = my_domains & comparison
    cleaned = my_domains - comparison

    print(f"Removed: {len(removed):,}")
    print(f"Remaining: {len(cleaned):,}")

    with open(OUTPUT_FILE, "w") as f:
        for domain in sorted(cleaned):
            f.write(domain + "\n")

    print(f"\nSaved cleaned list to {OUTPUT_FILE}")


if __name__ == "__main__":
    main()
