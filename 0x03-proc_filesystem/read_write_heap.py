#!/usr/bin/python3
"""change string in heap"""
from sys import argv


def parse_maps_file(pid):
    """sets /maps file into heap"""
    start = None
    stop = None
    try:
        with open("/proc/{:d}/maps".format(pid), "r") as f:
            for l in f:
                if l.endswith("[heap]\n"):
                    start, stop = \
                        [int(x, 16) for x in l.split(" ")[0].split("-")]
    except Exception as a:
        print(a) or exit(1)
    if not start or not stop:
        print("[ERROR] Heap address not found.") or exit(1)
    print("[*] Heap starts at {:02X}".format(start))
    return start, stop


def update_mem_file(pid, search_string, replace_string, start, stop):
    """finds string in /mem file changes it"""
    try:
        with open("/proc/{:d}/mem".format(pid), "r+b") as fi:
            fi.seek(start)
            data = fi.read(stop - start)
            print("[*] Read {:d} bytes".format(stop - start))
            str = data.find(search_string.encode())
            if str > -1:
                print("[*] String found at {:02X}"
                      .format(start + str))
                fi.seek(start + str)
                w = fi.write(replace_string.encode() + b'\x00')
                print("[*] {:d} bytes written!".format(w))
            else:
                print(
                    "[ERROR] String '{:s}' not found in heap."
                    .format(search_string))
                exit(1)
    except Exception as a:
        print(a) or exit(1)

if __name__ == "__main__":
    if len(argv) < 4 or len(argv[2]) < len(argv[3]):
        exit(1)
    start, stop = parse_maps_file(int(argv[1]))
    update_mem_file(int(argv[1]), argv[2], argv[3], start, stop)
