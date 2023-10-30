// Strings

//Here is an example implementation of an algorithm to find a substring:
// Finds the position of a substring withing a string.
// Returns false if the substring does not exist within the string.
bool find_substr(const char *str, const char *substr, size_t *out) {
    for (size_t i = 0; str[i] != 0; i++) {
        // Compare with each character of the desired substring.
        bool found = true;
        for (size_t j = 0; substr[j] != 0; j++) {
            if (str[i + j] != substr[j]) {
                found = false;
                break;
            }
        }
    // All characters matched the substring.
        if (found) {
            *out = i;
            return true;
        }
    }
    // We did not find the substring.
    return false;
}



// Attempted extraction algorithm
// Allocates new memory for the given substring and extracts it.
char *extract_substr(const char *str, size_t start, size_t length) {
// Allocate memory. We add 1 to ensure there is room for the null-terminator.
    char *buf = malloc(length + 1);
// Copy the string contents.
    memmove(buf, str + start, length);
// Set the null-terminator.
    buf[length] = 0;
    return buf;
}

// Revised from above
// Allocates new memory for the given substring and extracts it.
char *extract_substr(const char *str, size_t start, size_t length) {
    // Allocate memory. We add 1 to ensure there is room for the null-terminator.
    char *buf = malloc(length + 1);
    // Make sure that 'start' is not past the end of the string.
    for (size_t i = 0; i < start; i++)
        if (str[i] == 0) {
            buf[0] = 0;
            return buf;
        }
    // Copy the string, up to 'length' characters.
    strncpy(buf, str + start, length);
    // Set the null-terminator.
    buf[length] = 0;
    return buf;
}
