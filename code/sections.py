import pathlib

from elftools.elf.elffile import ELFFile


current = pathlib.Path(__file__).parent

with open(current / "hello_compiled_linux.elf", "rb") as f:
    e = ELFFile(f)
    print("遍历所有的段:")
    for section in e.iter_sections():
        print(hex(section["sh_addr"]), section.name)

