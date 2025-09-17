#!/usr/bin/env python3

import sys
import re
import os

def extract_functions_from_file(file_path):
    """Extract function signatures and their logic from a C file."""
    with open(file_path, 'r') as f:
        content = f.read()

    # Pattern to match function definitions
    # This is a simple pattern, may need refinement for complex cases
    func_pattern = r'^\s*[\w\s\*]+\s+(\w+)\s*\([^)]*\)\s*\{'
    functions = []

    lines = content.split('\n')
    i = 0
    while i < len(lines):
        line = lines[i]
        match = re.match(func_pattern, line)
        if match:
            func_name = match.group(1)
            # Find the opening brace
            brace_count = line.count('{') - line.count('}')
            start_line = i
            i += 1
            while i < len(lines) and brace_count > 0:
                brace_count += lines[i].count('{') - lines[i].count('}')
                i += 1
            end_line = i - 1
            # Extract the function body
            func_body = '\n'.join(lines[start_line:end_line+1])
            # Extract signature (first line)
            signature = lines[start_line].strip()
            # Logic is the body without signature
            logic = '\n'.join(lines[start_line+1:end_line]) if start_line + 1 <= end_line else ""
            functions.append({
                'name': func_name,
                'signature': signature,
                'logic': logic.strip(),
                'file': file_path
            })
        else:
            i += 1

    return functions

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 extract_functions.py file1.c file2.c ...")
        sys.exit(1)

    all_functions = []
    for file_path in sys.argv[1:]:
        if os.path.exists(file_path):
            functions = extract_functions_from_file(file_path)
            all_functions.extend(functions)

    # Write to functions.json or something
    import json
    with open('functions.json', 'w') as f:
        json.dump(all_functions, f, indent=2)

    # Also write names for compatibility
    with open('functions.txt', 'w') as f:
        for func in all_functions:
            f.write(func['name'] + '\n')

if __name__ == '__main__':
    main()