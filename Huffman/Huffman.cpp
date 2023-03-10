#include "bbtree2.h"

typedef pair<int,pair<Tnode<char>*,int>> pti;
typedef pair<int,pair<string,char>> psi;



map<char,string>crip;
map<string,char>descrip;

bool ordenas(pti A, pti B){
	if(A.second.first->Peso < B.second.first->Peso) return true;
	if(A.second.first->Peso > B.second.first->Peso) return false;
	if(A.second.first->D =='-') return true;
	if(B.second.first->D =='-') return true;
	if(A.second.second >= B.second.second  ) return true;
	return false;
}
	
void code (Tnode<char>*R,string ss=""){
	if(R->right!=0){
		code(R->right,ss+'1');
	}
	if(R->left!=0){
		code(R->left,ss+'0');
	}
	if(R->D!='_'){
		if(ss==""){
			ss='1';
		}
		crip[R->D]=ss;
		descrip[ss]=R->D;
	}
}



int main(){
	//deve usar um arquivo "input.txt" para ler e um "output.txt" para receber o arquivo
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string frase;
	string str="";
	list<pti> pq;
	vector<string> save;
	while(getline(cin,frase)){
		str=str+frase+'\n';
	}
	//string lida
	char jj=0;
	//par ver melhor caso digite espaso ele será representado pelo menos(-)
	
	vector<pair<char,pair<int,int>>>freq(100);
	for(int i=32;i<=126;i++){
		freq[i-32].first=jj+i;
		freq[i-32].second.first=0;
		freq[i-32].second.second=0;
	}
	for(int j=0;j<int(str.size());j++){
		for(int i=32;i<=126;i++){
			if(freq[i-32].first==str[j] ){
				freq[i-32].second.first=freq[i-32].second.first+1;
				if(freq[i-32].second.second==0){
					freq[i-32].second.second=j;
				}
				i=127;
			}
		}
	}
	for(int i=32;i<=126;i++){
		if(freq[i-32].second.first!=0){
			bbtree<char>aux;
			aux.insert(freq[i-32].first,freq[i-32].second.first);
			Tnode<char>* Z=aux.getRoot();
			pq.push_back({freq[i-32].second.first,{Z,freq[i-32].second.second}});
		}
	}
	pq.sort(ordenas);
	while(pq.size()!=1){
		pti x=pq.front();
		pq.pop_front();
		pti y=pq.front();
		pq.pop_front();
		bbtree<char>aux(x.second.first,y.second.first);
		Tnode<char>* Z=aux.getRoot();
		pq.push_back({x.first+y.first,{Z,x.second.second+y.second.second}});
		pq.sort(ordenas);
	}
	bbtree<char>aux;
	code(pq.front().second.first);
	cout<<"Frase :"<<endl;
	cout<<endl;
	for(int i=0;i<int(str.size());i++){
		if(str[i]!='*'){
			cout<<str[i];
		}
		else{
			cout<<endl;
		}
	}
	cout<<endl;
	cout<<endl;
	cout<<"Dicionario :"<<endl;
	cout<<endl;
	for(auto i: crip){
		if(i.first=='-'){
			cout<<" "<<" "<<i.second<<endl;
		}
		else{
			cout<<i.first<<" "<<i.second<<endl;
		}
	}
	cout<<endl;
	cout<<"Frase criptografada :"<<endl;
	cout<<endl;
	for(int j=0;j<int(str.size());j++){
		if(str[j]=='\n'){
			cout<<endl;
		}
		else{
			
			if(str[j]==' '){
				cout<<crip['-']<<" ";
				save.push_back(crip['-']);
			}
			else{
				cout<<crip[str[j]]<<" ";
				save.push_back(crip[str[j]]);
			}
		}
	}
	cout<<endl;
	
}
