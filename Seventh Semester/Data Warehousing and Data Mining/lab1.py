import pandas as pd
from io import StringIO

data = """ID,Name,Duration,Rating,Genre
1,Inception,148,8.8,Sci-Fi

2,The Godfather,175,9.2,Crime
3,Interstellar,,8.6,Sci-Fi
,,,,
4,Parasite,132,,Thriller
5,The Dark Knight,152,9.0,
6,,120,7.5,Drama

7,Forrest Gump,142,8.8,Comedy
8,Avatar,,7.8,Sci-Fi
9,Gladiator,155,,Action
10,Titanic,195,7.9,
"""

df = pd.read_csv(StringIO(data))

# Treat empty strings as NaN
df.replace(r'^\s*$', pd.NA, regex=True, inplace=True)

# Drop fully empty rows
df.dropna(how='all', inplace=True)

# Fill missing values with 100
df.fillna(100, inplace=True)

print(df)
