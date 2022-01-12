#include <bits/stdc++.h>
using namespace std;


vector<double> solve(vector<vector<double>> arr){
	int n = arr.size();
	for(int i = 0;i < n;i++){
		double maxEl = abs(arr[i][i]);
		int maxRow = i;
		for(int j = i+1;j < n;j++){
			if(abs(arr[j][i]) > maxEl){
				maxEl = abs(arr[j][i]);
				maxRow = j;
			}
		}
		for(int j = i;j < n+1;j++){
			double temp = arr[maxRow][j];
			arr[maxRow][j] = arr[i][j];
			arr[i][j] = temp;
		}
		for(int j = i+1;j < n;j++){
			double col = -arr[j][i]/arr[i][i];
			for(int k = i;k < n+1;k++){
				if(i == k){
					arr[j][k] = 0;
				}else{
					arr[j][k] += col*arr[i][k];
				}
			}
		}
	}
	vector<double> solution(n);
	for(int i = n-1;i >= 0;i--){
		solution[i] = arr[i][n]/arr[i][i];
		for(int j = i-1;j >= 0;j--){
			arr[j][n] -= arr[j][i]*solution[i];
		}
	}
	return solution;
}

int main(){
        //freopen("input.txt","r",stdin)
	int n;
	cin >> n;
	vector<vector<double>> arr; 
	for(int i = 0;i < n;i++){
		vector<double> row;
		for(int j = 0;j < n+1;j++){
			int val;
			cin >> val;
			row.push_back(val);
		}
		arr.push_back(row);
	}
	vector<double> sol;
	sol = solve(arr);
	for(int i = 0;i < sol.size();i++){
		cout << sol[i] << " ";
	}
}
