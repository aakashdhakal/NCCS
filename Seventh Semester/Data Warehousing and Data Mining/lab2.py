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

3,Interstellar,,8.6,Sci-Fi
6,,120,7.5,Drama
9,Gladiator,155,,Action


"""

# Load dataset
df = pd.read_csv(StringIO(data))

# Replace empty strings with NaN
df.replace(r'^\s*$', pd.NA, regex=True, inplace=True)

# Drop completely empty rows
df.dropna(how='all', inplace=True)

# Fill missing values with 100
df.fillna(100, inplace=True)

print("Original Data:")
print(df)

# Ensure 'Duration' is numeric for comparison
df['Duration'] = pd.to_numeric(df['Duration'], errors='coerce')

# Drop rows where Duration > 120
df = df[df['Duration'] <= 120]

print("\nAfter Removing Rows with Duration > 120:")
print(df.to_string(index=False))

duplicates = df.duplicated()
print("\nDuplicate Rows Found (Boolean Mask):")
print(duplicates.to_string(index=False))

all_duplicates = duplicates.all()
print("\nAre all rows duplicates?:", "Yes" if all_duplicates else "No")

duplicate_count = duplicates.sum()
print(f"\nNumber of duplicate rows: {duplicate_count}")

print("\nCleaned Dataset:")
print(df.to_string(index=False))
