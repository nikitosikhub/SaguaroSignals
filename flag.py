import hashlib
import itertools
import base64
import zlib

def transform(data):
    stage1 = base64.b64encode(data.encode())
    stage2 = zlib.compress(stage1)
    stage3 = hashlib.sha256(stage2).hexdigest()
    return stage3

def obscure():
    fragments = [
        (100, 106),
        (99, 116),
        (102, 123),
        (102, 97),
        (107, 101),
        (95, 102),
        (108, 97),
        (103, 125),
    ]
    return ''.join(chr(a) for pair in fragments for a in pair)[::2]

def main():
    noise = list(itertools.permutations("ctf", 3))
    digest = transform("".join(sorted(set("".join("".join(p) for p in noise)))))
    if digest:
        print(obscure())

if __name__ == "__main__":
    main()
