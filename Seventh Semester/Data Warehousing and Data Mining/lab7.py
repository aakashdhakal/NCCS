import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import DBSCAN
X = np.array([
    [1, 2], [2, 1], [2, 2], [3, 2], [2, 3], [1, 3], [3, 1], [3, 3],
    [8, 7], [8, 8], [7, 7], [7, 8], [9, 8], [8, 9], [9, 7], [7, 9],
    [25, 25], [30, 30], [26, 26], [29, 29], [28, 27], [27, 28], [31, 31], [32, 32]
])
dbscan = DBSCAN(eps=2, min_samples=2)
clusters = dbscan.fit_predict(X)
print("Cluster labels for each point:")
print(clusters)
plt.scatter(X[:, 0], X[:, 1], c=clusters, cmap='viridis', marker='o')
plt.title("DBSCAN Clustering")
plt.xlabel("Feature 1")
plt.ylabel("Feature 2")
plt.show()