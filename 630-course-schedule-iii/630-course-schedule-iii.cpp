class Solution {
public:

	static bool compare(vector<int>&a, vector<int>&b){
		if(a[1]==b[1])
			return a[0]<b[0];
		return a[1]<b[1];
	}

	int scheduleCourse(vector<vector<int>>& courses) {

		priority_queue<int>pq;
		int ttime = 0;
		sort(courses.begin(), courses.end(), compare);
		for(int i=0;i<courses.size();i++){
			if(ttime + courses[i][0] <= courses[i][1]){
				ttime += courses[i][0];
				pq.push(courses[i][0]);
			}
			else if(!pq.empty() && pq.top() > courses[i][0]){
				ttime -= pq.top();
				pq.pop();
				pq.push(courses[i][0]);
				ttime += courses[i][0];
			}

		}
		return pq.size();
	}
};