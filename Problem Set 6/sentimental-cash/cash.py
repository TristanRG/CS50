from cs50 import get_float

change = get_float("Change: ")
while change <= 0:
    change = get_float("Change: ")

cents = round(change * 100)
coins = 0

coins += cents // 25
cents %= 25

coins += cents // 10
cents %= 10

coins += cents // 5
cents %= 5

coins += cents // 1

print(f"{coins}")
