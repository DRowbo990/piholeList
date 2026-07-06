from collections import defaultdict
import tldextract

INPUT_FILE = "list.txt"
OUTPUT_FILE = "optimized.txt"


def normalize(line: str) -> str:
    return line.strip().lower()


def is_comment(line: str) -> bool:
    return line.startswith("!") or line.startswith("#") or line == ""


def main():
    # raw storage
    domains = []

    with open(INPUT_FILE, "r") as f:
        for line in f:
            line = normalize(line)
            if is_comment(line):
                continue

            # strip ABP syntax if already present
            if line.startswith("||"):
                line = line[2:]
            if line.endswith("^"):
                line = line[:-1]

            domains.append(line)

    # group by registrable domain
    groups = defaultdict(set)

    for d in domains:
        ext = tldextract.extract(d)

        # skip malformed entries
        if not ext.domain or not ext.suffix:
            continue

        root = f"{ext.domain}.{ext.suffix}"
        groups[root].add(d)

    optimized = set()

    for root, items in groups.items():
        items = set(items)

        apex = root in items

        # SAFE compression rule:
        # only compress when apex domain is already explicitly present
        # or when there are multiple subdomains AND apex exists
        if apex and len(items) > 1:
            optimized.add(f"||{root}^")
        else:
            # keep original entries (restore ABP format for consistency)
            for item in items:
                optimized.add(item)

    # write output
    with open(OUTPUT_FILE, "w") as f:
        for d in sorted(optimized):
            if not d.startswith("||"):
                f.write(d + "\n")
            else:
                f.write(d + "\n")


if __name__ == "__main__":
    main()
