class Solution {
	int colors[26] = {0};
	vector<vector<int>> graph;
	vector<int> indegree;
	vector<array<int, 26>> colorMapping;
	int numElements;

	void edgesToGraph(vector<vector<int>>& edges) {
		graph.assign(numElements, vector<int>{});
		indegree.assign(numElements, 0);

		for (vector<int>& edge : edges) {
			graph[edge[0]].push_back(edge[1]);
			indegree[edge[1]]++;
		}
	}
public:
	int largestPathValue(string colors, vector<vector<int>>& edges) {
		numElements = colors.size();
		colorMapping.assign(numElements, array<int, 26>{});
		edgesToGraph(edges);

		queue<int> q;
		for (int i = 0; i < numElements; i++) {
			if (!indegree[i]) q.push(i);
		}

		int temp;
		int maxColor = 0;
		while (!q.empty()) {
			temp = q.front();
			q.pop();
			colorMapping[temp][colors[temp] - 'a']++;
			for (int i = 0; i < 26; i++) {
				if (!colorMapping[temp][i]) continue;
				maxColor = max(maxColor, colorMapping[temp][i]);
			}	

			for (int nbr : graph[temp]) {
				if (indegree[nbr]) {
					indegree[nbr]--;
					for (int i = 0; i < 26; i++) {
						if (!colorMapping[temp][i]) continue;
						colorMapping[nbr][i] = max(colorMapping[nbr][i], colorMapping[temp][i]);
					}
					if (!indegree[nbr]) {
						q.push(nbr);					
					}
				}
			}
		}

        for (int i = 0; i < numElements; i++) {
            if (indegree[i]) return -1;
        }


		return maxColor;

	}
};