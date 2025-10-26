# Problem Statement: Check if a given string is a valid email address or not.
# Time Complexity: O(N)  → where N is the length of the string.
# Space Complexity: O(1)

import re

def is_valid_email(email):
    """
    Function to validate an email address using Regular Expressions.
    
    Args:
        email (str): The email address to validate.
    Returns:
        bool: True if valid, False otherwise.
    """
    pattern = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
    return bool(re.match(pattern, email))

print("Email Validator Program")
print("=======================")

while True:
    email = input("Enter an email to validate (or type 'exit' to quit): ").strip()
    if email.lower() == 'exit':
        print("Exiting program.")
        break
    if is_valid_email(email):
        print(f"{email} -> Valid Email Address")
    else:
        print(f"{email} -> Invalid Email Address")
