#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
 
using namespace std;
#define ii pair<int,int>
#define pb push_back
int n;int e,source;
vector<ii> g[100000];
int dist[100000];
bool marked[100000];
void apply_dijkstra()
{
	set<ii > s;
	s.insert(ii(0,source));
	dist[source] = 0;marked[source] = 1;
	while(!s.empty())
	{	
		ii p = *s.begin();	
		s.erase(p);
		marked[p.second] = 2;
		for(int i=0;i<g[p.second].size();i++)
			if(marked[g[p.second][i].second]==0)
			{
				s.insert(ii(dist[p.second]+g[p.second][i].first,g[p.second][i].second));
				marked[g[p.second][i].second] = 1;
				dist[g[p.second][i].second] = dist[p.second]+g[p.second][i].first;
			}
			else if(marked[g[p.second][i].second]==1 && dist[g[p.second][i].second] > dist[p.second]+g[p.second][i].first)
			{
				s.erase(ii(dist[g[p.second][i].second],g[p.second][i].second));
				s.insert(ii(dist[p.second]+g[p.second][i].first,g[p.second][i].second));
				dist[g[p.second][i].second] =  dist[p.second]+g[p.second][i].first;
			} 
	}
	printf("La distancia mas corta:\n");
	for(int i=1;i<=n;i++)
	{
		printf("Nodo %d - %d\n",i,dist[i]);
	}
	printf("\n");
}
 
int main()
{
	printf("Dijkstra\n\n");
	printf("Introduce el numero de nodos:\n");
	scanf("%d",&n);
	printf("Introduce el numero de caminos:\n");
	int e;scanf("%d",&e);
	printf("Intoduce las rutas a seguir y sus pesos ([origen] [destino] [peso])\nlos numeros de origen y destino se diferencian con numeros a partir del 1:\n");
	for(int i=0;i<e;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		g[y].pb(ii(w,x));
		g[x].pb(ii(w,y));
	}
	printf("Traza ruta de origen:\n");
	scanf("%d",&source);
	apply_dijkstra();
	system("PAUSE");
	return 0;
}
