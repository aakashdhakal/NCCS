import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

# Manually define a set of 2D points
X_manual = np.array([
    [1, 2], [2, 1], [2, 2], [2, 3], [1, 2],
    [8, 8], [9, 8], [8, 9], [9, 9], [8, 8],
    [20, 20], [21, 19], [20, 21], [21, 21], [21, 21],
    [3, 4], [4, 3], [3, 3], [4, 4], [3, 5],
    [10, 10], [11, 10], [10, 11], [11, 11], [10, 12],
    [22, 20], [23, 21], [22, 22], [23, 23], [22, 23], [23, 22]
])

# Apply K-means clustering (3 clusters)
kmeans = KMeans(n_clusters=3, random_state=0)
labels = kmeans.fit_predict(X_manual)
centers = kmeans.cluster_centers_

# Show cluster centers
print('Cluster centers (centroids):')
print(centers)
# Show cluster labels for each point
print('Cluster labels for each point:')
print(labels)

# Plotting the clusters and centroids
plt.figure(figsize=(8,6))
plt.scatter(X_manual[:, 0], X_manual[:, 1], c=labels, cmap='rainbow', s=80, edgecolor='k', label='Data Points')
plt.scatter(centers[:, 0], centers[:, 1], c='black', s=250, alpha=0.7, marker='X', label='Centroids')
plt.title('K-Means Clustering')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.legend()
plt.show()
