import pandas as pd
from mlxtend.preprocessing import TransactionEncoder
from mlxtend.frequent_patterns import apriori

# Sample transactional data as list of lists
transactions = [
    ['Laptop', 'Mouse', 'Keyboard', 'USB Drive', 'Headphones'],
    ['Phone', 'Charger', 'Headphones', 'Power Bank', 'Cover'],
    ['Tablet', 'Stylus', 'Cover', 'Charger', 'Headphones'],
    ['Laptop', 'Headphones', 'USB Drive', 'Keyboard', 'Mouse'],
    ['Phone', 'Laptop', 'Charger', 'Headphones', 'USB Drive'],
    ['Camera', 'Tripod', 'SD Card', 'Laptop', 'Headphones'],
    ['Phone', 'Cover', 'Headphones', 'Power Bank', 'Charger', 'Laptop'],
    ['Tablet', 'Charger', 'Stylus', 'Cover', 'Laptop', 'Mouse'],
    ['Laptop', 'Mouse', 'Keyboard', 'USB Drive', 'Headphones', 'Charger'],
    ['Camera', 'Laptop', 'Headphones', 'Phone', 'Charger', 'USB Drive']
]

# Convert transactions to one-hot encoded DataFrame
te = TransactionEncoder()
te_ary = te.fit(transactions).transform(transactions)
df = pd.DataFrame(te_ary, columns=te.columns_)

# Apply Apriori algorithm with minimum support = 0.5
frequent_itemsets = apriori(df, min_support=0.5, use_colnames=True)

print(frequent_itemsets)