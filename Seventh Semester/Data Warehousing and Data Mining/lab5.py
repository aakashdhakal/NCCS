import pandas as pd
from sklearn import svm
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report, accuracy_score

# Load and clean dataset
df = pd.read_csv("Seventh Semester/Data Warehousing and Data Mining/gender.csv");
df.columns = df.columns.str.strip()
df = df.loc[:, ~df.columns.str.contains('^Unnamed')]
df = df.dropna()

# Use all columns except 'Gender' as features, 'Gender' as target
X = df.drop('Gender', axis=1)
y = df['Gender']

# Encode categorical features and target
for col in X.columns:
    if X[col].dtype == 'object':
        X[col] = pd.factorize(X[col])[0]
if y.dtype == 'object':
    y = pd.factorize(y)[0]

# Split data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Train SVM (linear kernel)
clf = svm.SVC(kernel='linear')
clf.fit(X_train, y_train)

# Predict and evaluate
y_pred = clf.predict(X_test)
print("Accuracy:", accuracy_score(y_test, y_pred))
print("\nClassification Report:\n", classification_report(y_test, y_pred))

#Example Prediction
example = pd.DataFrame({
    'Age': [25],
    'Height (cm)': [170],
    'Weight (kg)': [70],
    'Occupation': ['Engineer'],
    'Education Level': ["Bachelor's Degree"],
    'Marital Status': ['Single'],
    'Income (USD)': [50000],
    'Favorite Color': ['Blue']
})
classes = ['Male', 'Female']
for col in example.columns:
    if example[col].dtype == 'object':
        example[col] = pd.factorize(example[col])[0]
prediction = clf.predict(example)
print("Predicted Gender:", classes[prediction[0]])
