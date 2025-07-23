# Read input
with open("tttt.in") as f:
    board = [list(line.strip()) for line in f]

lines = []

# rows
lines.extend(board)

# columns
for c in range(3):
    lines.append([board[r][c] for r in range(3)])

# diagonals
lines.append([board[i][i] for i in range(3)])
lines.append([board[i][2 - i] for i in range(3)])

individual_winners = set()
team_winners = set()

for line in lines:
    unique = set(line)
    if len(unique) == 1:
        individual_winners.add(line[0])
    elif len(unique) == 2:
        a, b = sorted(unique)
        if line.count(a) > 0 and line.count(b) > 0:
            team_winners.add((a, b))

with open("tttt.out", "w") as f:
    f.write(f"{len(individual_winners)}\n")
    f.write(f"{len(team_winners)}\n")
