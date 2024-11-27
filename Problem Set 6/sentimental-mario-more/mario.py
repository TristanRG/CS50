from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height < 1 or height > 8:
        continue
    else:
        break

for _ in range(height):
    print(f" " * (height - _ - 1) + "#" * (_ + 1) + "  "  + "#" * (_ + 1))
