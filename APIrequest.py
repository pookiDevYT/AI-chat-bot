import os
from huggingface_hub import InferenceClient

api_key = "YOUR API here"

input_file = "input.txt"
output_file = "output.txt"

if os.path.exists(input_file):
    with open(input_file, "r") as file:
        user_input = file.read()
else:
    raise FileNotFoundError(f"{input_file} not found.")

instructions = """
Please follow these instructions strictly:
1. Respond briefly and concisely.
2. Always answer in English.
3. Be clear and precise in your responses.
4. You should be able to chat and also provide programming assistance.
5. If asked about coding or programming, offer clear and understandable solutions in English.
"""

messages = [
    {"role": "system", "content": instructions},
    {"role": "user", "content": user_input}
]

client = InferenceClient(api_key=api_key)

try:
    completion = client.chat.completions.create(
        model="Qwen/Qwen2.5-Coder-32B-Instruct", 
        messages=messages, 
        max_tokens=500 
    )

    # Get the content of the response
    output_text = completion.choices[0].message['content']

    # Write the output to the output file
    with open(output_file, "w", encoding="utf-8") as file:
        file.write("code helper: " + output_text)

except Exception as e:
    print(f"An error occurred: {e}")
