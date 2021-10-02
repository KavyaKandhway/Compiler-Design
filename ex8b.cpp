#include<bits/stdc++.h>
using namespace std;
vector<string> eliminate_left_rec(vector<string> prod)
{
	map<char,int> pres;
	vector<string> production;
	for(int i = 0; i < prod.size(); i++) pres[prod[i][0]] = 1;
	for(int i = 0; i < prod.size(); i++){
		int j = i;
		if(prod[i][0] == prod[i][3]){
			//left recursion case
			vector<string> alpha, beta;
			for(int k = i; k < prod.size(); k++){
				if(prod[k][0] == prod[i][0]){
					if(prod[k][0] == prod[k][3]) alpha.push_back(prod[k].substr(4,prod[k].length() - 4));
					else beta.push_back(prod[k].substr(3,prod[k].length()-3));
					j = k;
				}else break;
			}
			string ch = "@";
			for(char c = 'A'; c <= 'Z'; c++){
				if(pres[c] == 0){
					pres[c] = 1;
					ch[0] = c;
					break;
				}
			}
			//cout << ch << "kd\n";
			for(int k = 0; k < beta.size(); k++){
				string p ="@";
				p[0]= prod[i][0];
				p+="->";
				p += (beta[k]);
				p+=ch;
				//cout << p << "\n\n";
				production.push_back(p);
			}
			for(int k = 0; k < alpha.size(); k++){
				 string p = ch+"->"+alpha[k]+ch;
				 production.push_back(p);
			}
			string p = "@";
			p[0]=ch[0];
			p+="->#";
			production.push_back(p);
		}else production.push_back(prod[i]);
		i = j;
	}
	return production;
}
map<char,vector<char> > first, follow;
map<pair<char,char>, string> M;
map<char,int> remem;
void first_cal(vector<string> production, char ch){
	//rule 1 and rule 2
	for(int i = 0; i < production.size(); i++){
		if(production[i][0] == ch){
			if(!(production[i][3] >= 'A' && production[i][3] <='Z')){
				//check whether production[i][3] is in first[production[i][0]]
				int done = 0;
				for(int j = 0; j < first[production[i][0]].size(); j++){
					if(first[production[i][0]][j] == production[i][3]){
						done = 1;
						break;
					}
				}
				if(!done){
					 first[production[i][0]].push_back(production[i][3]);
					if(production[i][3] != '#') M[make_pair(production[i][0],production[i][3])] = production[i];
					else remem[production[i][0]] = i;
				}
			}
		}
	}
	//rule 3
	for(int i = 0; i < production.size(); i++){
		if(production[i][0] == ch){
			int eps = 0;
			if(production[i][3] >= 'A' && production[i][3] <= 'Z'){
				first_cal(production, production[i][3]);
				for(int j = 0; j < first[production[i][3]].size(); j++){
					char ch = first[production[i][3]][j];
					if(ch == '#') eps = 1;
					int done = 0;
					for(int k = 0; k < first[production[i][0]].size(); k++){
						if(first[production[i][0]][k] == ch){
							done = 1;
							break;
						}
					}
					if(!done){
						first[production[i][0]].push_back(ch);
						if(ch != '#') M[make_pair(production[i][0],ch)] = production[i];
						else remem[production[i][0]] = i;
					}
				}
			}
			for(int k = 4; k <production[i].size(); k++){
				if(eps == 0) break;
				if(production[i][k] <'A' || production[i][k] > 'Z') break;
				first_cal(production, production[i][k]);
				int cur_eps = 0;
				for(int j = 0; j < first[production[i][k]].size(); j++){
					char ch = first[production[i][k]][j];
					if(ch == '#') cur_eps = 1;
					int done = 0;
					for(int k = 0; k < first[production[i][0]].size(); k++){
						if(first[production[i][0]][k] == ch){
							done = 1;
							break;
						}
					}
					if(!done){
						first[production[i][0]].push_back(ch);
						if(ch != '#') M[make_pair(production[i][0],ch)] = production[i];
						else remem[production[i][0]] = i;
					}
				}
				if(cur_eps == 0) eps = 0;
			}
		}
	}
}

void follow_calc(vector<string> production, char ch)
{
	// rule 2
	for(int i = 0; i < production.size(); i++)
	{
		for(int j = 3; j < production[i].length()-1; j++){
			if(production[i][j] >= 'A' && production[i][j] <= 'Z'){
				if(production[i][j] != ch) continue;
				if(production[i][j+1] >= 'A' && production[i][j+1] <= 'Z'){
					//put everything in first(beta) to follow(B)
					char beta = production[i][j+1], B = production[i][j];
					if(B != ch) continue;
					for(int k = 0; k < first[beta].size(); k++){
						if(first[beta][k] == '#') continue;
						int done = 0;
						for(int l = 0; l < follow[B].size(); l++){
							if(follow[B][l] == first[beta][k]){
								done = 1;
								break;
							}
						}
						if(!done) follow[B].push_back(first[beta][k]);
					}
				}else{
						char ch = production[i][j+1];
						int done = 0;
						for(int k = 0; k < follow[production[i][j]].size(); k++){
							if(follow[production[i][j]][k] == ch){
								done = 1;
								break;
							}
						}
						if(!done) follow[production[i][j]].push_back(ch);
				}
			}
		}
	}
	
	//rule 3
	for(int i = 0; i < production.size(); i++)
	{
		for(int j = 3; j < production[i].length(); j++)
		{
			if(production[i][j] < 'A' || production[i][j] > 'Z') continue;
			if(production[i][j] == production[i][0]) continue;
			int eps = 1;
			for(int k = j+1; k < production[i].length(); k++){
				char ch = production[i][k];
				int c_eps = 0;
				for(int l = 0; l < first[ch].size(); l++){
					if(first[ch][l] == '#'){
						c_eps = 1;
						break;
					}
				}
				if(c_eps== 0) eps = 0;
			}
			if(eps == 0) continue;
			if(production[i][j]!=ch) continue;
			follow_calc(production, production[i][0]);
			char A = production[i][0], B = production[i][j];
			for(int k = 0; k < follow[A].size(); k++){
				char ch = follow[A][k];
				int done = 0;
				for(int l = 0; l < follow[B].size(); l++){
					if(follow[B][l] == ch){
						done = 1;
						break;
					}
				}
				if(!done) follow[B].push_back(ch);
			}
		}
	}
}

int main()
{
	vector<string> production;
	production.push_back("S->A");
	production.push_back("A->Ad"); production.push_back("A->aB");
	production.push_back("B->bBC"); production.push_back("B->f");
	production.push_back("C->g"); 
	
	production = eliminate_left_rec(production);
	
	
	//first calculation
	cout << "FIRST CALCULATIONS: \n";
	map<char,int> calc;
	for(int i = 0; i < production.size(); i++){
		if(calc[production[i][0]] == 0){
			calc[production[i][0]] = 1;
			first_cal(production, production[i][0]);
			cout <<"FIRST(" << production[i][0] << ") = ";
			for(int j = 0; j < first[production[i][0]].size(); j++){
				cout << first[production[i][0]][j] << " ";
			}
			cout << "\n";
		}
	}
	cout << "\n\n";
	//follow calculation
	cout << "FOLLOW CALCULATION: \n";
	follow[production[0][0]].push_back('$');
	calc.clear();
	for(int i = 0; i < production.size(); i++){
		if(calc[production[i][0]] == 0){
			calc[production[i][0]] = 1;
			follow_calc(production, production[i][0]);
			cout <<"FOLLOW(" << production[i][0] << ") = ";
			for(int j = 0; j < follow[production[i][0]].size(); j++){
				cout << follow[production[i][0]][j] << " ";
			}
			cout << "\n";
		}
	}
	cout << "\n\n";
	cout << "Parsing table values: \n";
	//table calcualtion
	map<char,int>::iterator it;
	for(it = remem.begin(); it!=remem.end(); it++){
		char A = (*it).first;
		int ind = (*it).second;
		for(int i = 0; i < follow[A].size(); i++){
			char b = follow[A][i];
			M[make_pair(A,b)] = production[ind];
		}
	}
	map<pair<char,char>,string>::iterator it1;
	map<pair<char,char>,int> mp;
	for(it1 = M.begin(); it1!=M.end(); it1++){
		mp[(*it1).first] = 1;
		cout << "M["<<(*it1).first.first << "," << (*it1).first.second << "] = " << (*it1).second << "\n";
	}
	cout << "\n\n";
    cout<<"\nParser Running ...\n\n";
	cout << "Enter the input strings: \n";
	while(1){
		string s;
		cin >> s;
		stack<char> st;
		s += "$";
		st.push('$');
		st.push(production[0][0]);
		int poin = 0, ac = 0;
		while(poin < s.length()){
			char X = st.top(),a = s[poin];
			if(X >= 'A' && X <= 'Z'){
				if(mp[make_pair(X,a)] == 0) break;
				string m = M[make_pair(X,a)].substr(3,M[make_pair(X,a)].length()-3);
				reverse(m.begin(),m.end());
				st.pop();
				if(m == "#") continue;
				for(int i = 0; i < m.length(); i++) st.push(m[i]);
			}else{
				if(X == a){
					if(X == '$'){
						ac = 1;
						break;
					}else{
						st.pop();
						poin++;
					}
				}else break;
			}
		}
		if(ac) cout << "Succesfully Parsed.\n";
		else cout << "Parsing Failed.\n";
	}
	
	return 0;
}