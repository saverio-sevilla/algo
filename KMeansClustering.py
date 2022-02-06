import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs


def euclidean_dist(x1, x2):
    return np.sqrt(np.sum((x1-x2)**2))

class KMeans:

    def __init__(self, K):
        # number of clusters
        self.K = K

        # mean vectors for each cluster
        self.centroids = []

    def classify(self, X):
        self.X = X
        self.n_samples, self.n_features = X.shape

        # initialization of centroids

        self.centroids = X[np.random.choice(self.X.shape[0], self.K, replace=False), :]

        while (True):

            self.clusters = self._create_clusters(self.centroids)
            centroids_old = self.centroids
            self.centroids = self._get_centroids(self.clusters)


            if self._is_converged(centroids_old, self.centroids):
                break

        return self._get_labels(self.clusters)

    def _get_labels(self, clusters):
        labels = np.empty(self.n_samples)

        for cluster_idx, cluster in enumerate(clusters):
            for sample_idx in cluster:
                labels[sample_idx] = cluster_idx
        return labels

    def _create_clusters(self, centroids):
        clusters = [[] for i in range(self.K)]
        for idx, sample in enumerate(self.X):
            centroid_idx = self._closest_centroid(sample, centroids)
            clusters[centroid_idx].append(idx)

        return clusters

    def _closest_centroid(self, sample, centroids):
        distances = [euclidean_dist(sample, centroid) for centroid in centroids]
        closest_idx = np.argmin(distances)
        return closest_idx

    def _get_centroids(self, clusters):
        centroids = np.zeros((self.K, self.n_features))
        for cluster_idx, cluster in enumerate(clusters):
            cluster_mean = np.mean(self.X[cluster], axis = 0)
            centroids[cluster_idx] = cluster_mean
        return centroids

    def _is_converged(self, centroids_old, centroids):
        distances = [euclidean_dist(centroids_old[i], centroids[i]) for i in range(self.K)]
        return sum(distances) == 0


    def plot(self):
        fig, ax = plt.subplots(figsize = (12,8))

        for i, index in enumerate(self.clusters):
            point = self.X[index].T
            ax.scatter(*point, marker=".")

        for point in self.centroids:
            ax.scatter(*point, marker="x", color="black", linewidth=2)

        plt.show()


def main():

    X, y = make_blobs(centers=4, n_samples=500, n_features=2, shuffle=True)
    clusters = len(np.unique(y))
    k = KMeans(K=clusters)
    y_pred = k.classify(X)
    k.plot()

if __name__ == "__main__":
    main()

