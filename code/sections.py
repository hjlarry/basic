import pathlib

from elftools.elf.elffile import ELFFile
import capstone


current = pathlib.Path(__file__).parent

with open(current / "hello_compiled_linux.elf", "rb") as f:
    e = ELFFile(f)
    print("遍历所有的段:")
    for section in e.iter_sections():
        print(hex(section["sh_addr"]), section.name)
    print("-" * 20)

    code = e.get_section_by_name(".text")
    ops = code.data()
    addr = code["sh_addr"]
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    for i in md.disasm(ops, addr):
        print(f"0x{i.address:x}:\t{i.mnemonic}\t{i.op_str}")

