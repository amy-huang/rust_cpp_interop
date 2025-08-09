#[unsafe(no_mangle)]
pub extern "C" fn printPhrase(ptr: *const u8, len: usize) {
    if ptr.is_null() { return; }
    let bytes = unsafe { std::slice::from_raw_parts(ptr, len) };
    println!("{}", String::from_utf8_lossy(bytes));
}

pub const GREETING: &'static str = "Hallo, Rust library here!";
