// rust_g.dm - DM API for rust_g extension library
#define RUST_G "rust_g"
#define CPP_G "rcpp"
#define rustg_dmi_strip_metadata(fname) call(RUST_G, "dmi_strip_metadata")(fname)

#define ru_cpp(text) call(CPP_G, "ru_log")(text)

#define rustg_log_write(fname, text) call(RUST_G, "log_write")(fname, ru_cpp(text))

/proc/rustg_log_close_all() return call(RUST_G, "log_close_all")()