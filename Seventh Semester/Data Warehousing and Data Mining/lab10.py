import pandas as pd
from sklearn.tree import DecisionTreeClassifier, export_text, plot_tree
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt

# New Dataset: Fruits Classification
data = {
    'Fruit': [
        'Apple', 'Banana', 'Orange', 'Grape', 'Watermelon', 'Pineapple', 'Strawberry', 'Blueberry',
        'Mango', 'Papaya', 'Lemon', 'Cherry', 'Peach', 'Plum', 'Kiwi', 'Guava', 'Pear', 'Fig', 'Date', 'Lychee'
    ],
    'Weight': [150, 120, 130, 5, 3000, 900, 12, 1, 200, 500, 70, 8, 150, 50, 75, 180, 170, 50, 7, 20],
    'Color': [
        'Red', 'Yellow', 'Orange', 'Purple', 'Green', 'Brown', 'Red', 'Blue',
        'Yellow', 'Orange', 'Yellow', 'Red', 'Pink', 'Purple', 'Brown', 'Green', 'Green', 'Purple', 'Brown', 'Red'
    ],
    'Taste': [
        'Sweet', 'Sweet', 'Citrus', 'Sweet', 'Sweet', 'Sweet', 'Sweet', 'Sweet',
        'Sweet', 'Sweet', 'Citrus', 'Sweet', 'Sweet', 'Sweet', 'Tangy', 'Sweet', 'Sweet', 'Sweet', 'Sweet', 'Sweet'
    ],
    'Category': [
        'Common', 'Common', 'Common', 'Common', 'Tropical', 'Tropical', 'Berry', 'Berry',
        'Tropical', 'Tropical', 'Citrus', 'Berry', 'Common', 'Common', 'Tropical', 'Tropical', 'Common', 'Tropical', 'Tropical', 'Tropical'
    ]
}

df = pd.DataFrame(data)
df_encoded = pd.get_dummies(df[['Weight', 'Color', 'Taste']])
X = df_encoded
y = df['Category']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
clf = DecisionTreeClassifier(criterion="entropy", max_depth=4, min_samples_leaf=2, random_state=42)
clf.fit(X_train, y_train)
print("\nDecision Tree Rules:\n")
print(export_text(clf, feature_names=list(X.columns)))
plt.figure(figsize=(14,8))
plot_tree(clf, feature_names=list(X.columns), class_names=clf.classes_, filled=True, rounded=True)
plt.title("Decision Tree (ID3 - Entropy) for Fruit Classification")
plt.show()
acc = clf.score(X_test, y_test)
print(f"\nTest Accuracy: {acc*100:.2f}%")
test_data = pd.DataFrame({
    'Weight': [100, 2500, 10],
    'Color': ['Red', 'Green', 'Blue'],
    'Taste': ['Sweet', 'Sweet', 'Sweet']
})
test_data_encoded = pd.get_dummies(test_data).reindex(columns=X.columns, fill_value=0)
predictions = clf.predict(test_data_encoded)
print("\nTest Predictions:")
for w, c, pred in zip(test_data['Weight'], test_data['Color'], predictions):
    print(f"Weight: {w}, Color: {c} => Predicted Category: {pred}")
