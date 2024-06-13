#include <iostream>
#include <format>

extern "C" {
#include "libbpf.h"
}

#define PROJECT_NAME "ebpf_decoder"

void disassemble_ebpf(const char* filename) {
    struct bpf_object *obj;
    struct bpf_program *prog;

    // Load the eBPF object file
    obj = bpf_object__open(filename);
    if (libbpf_get_error(obj)) {
        std::cerr << "Failed to open eBPF object file\n";
        return;
    }

    // Iterate over the programs in the object
    bpf_object__for_each_program(prog, obj) {
        size_t ins_cnt = bpf_program__insn_cnt(prog);
        const struct bpf_insn *ins = bpf_program__insns(prog);

        // Disassemble each instruction and print it
        for (size_t i = 0; i < ins_cnt; i++) {
            std::cout << std::format("{:8d}:\tOPCODE:{:02x} DST_REG:{:01x} SRC_REG:{:01x} OFFSET:{:04x} IMM:{:08x}\n", i, ins[i].code, ins[i].dst_reg, ins[i].src_reg, ins[i].off, ins[i].imm);
        }
    }

    // Unload the eBPF object file
    bpf_object__close(obj);
}

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << argv[0] <<  " requires an eBPF object file as an argument.\n";
        return 1;
    }
    std::cout << "This is project " << PROJECT_NAME << ".\n";
    disassemble_ebpf(argv[1]);
    return 0;
}
