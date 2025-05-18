cdef extern from "dwr.h":
    int dwr_randomize(const char* input_file, long seed, char *flags, const char *sprite_name, const char* output_dir)

def py_dwr_randomize(input_file: bytes, seed: long, flags: bytes) -> int:
    dwr_randomize(input_file, seed, flags, "", "/home/peter/")
