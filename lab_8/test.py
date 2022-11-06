from saes import SimplifiedAES

plaintext = 0b1101011100101000
key = 0b0100101011110101
ciphertext = SimplifiedAES(key).encrypt(plaintext)

print(ciphertext)