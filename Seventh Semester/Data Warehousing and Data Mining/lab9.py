from pyclustering.cluster.kmedoids import kmedoids
import numpy as np
import matplotlib.pyplot as plt


X = np.array([
    [1, 2], [1, 3], [2, 2], [2, 3], [1, 1],
    [2, 1], [0, 2], [0, 1], [1, 4], [2, 4],
    [5, 5], [5, 6], [6, 5], [6, 6], [4, 5],
    [4, 6], [5, 4], [6, 4], [5, 7], [6, 7],
    [9, 1], [9, 2], [10, 1], [10, 2], [8, 1],
    [8, 2], [9, 0], [10, 0], [8, 0], [11, 1],
    [14, 8], [14, 9], [15, 8], [15, 9], [13, 8],
    [13, 9], [14, 7], [15, 7], [13, 7], [16, 8]
])

# Choose initial medoid indices (for example, first 3 points)
initial_medoids = [0, 5, 10, 15]

# Run K-Medoids using pyclustering
kmedoids_instance = kmedoids(X.tolist(), initial_medoids)
kmedoids_instance.process()
clusters = kmedoids_instance.get_clusters()
medoids = kmedoids_instance.get_medoids()

# Print medoids in console
print("Medoids indices:", medoids)
print("Medoids coordinates:")
for idx in medoids:
    print(X[idx])

# Assign cluster labels for plotting
labels = np.zeros(len(X), dtype=int)
for cluster_id, cluster in enumerate(clusters):
    for index in cluster:
        labels[index] = cluster_id

# Plot results
plt.scatter(X[:, 0], X[:, 1], c=labels, cmap='viridis', marker='o')
plt.scatter(X[medoids, 0], X[medoids, 1], c='red', marker='x', s=200, label='Medoids')
plt.title('K-Medoids Clustering (pyclustering)')
plt.legend()
plt.show()
