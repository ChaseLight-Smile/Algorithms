//带路径压缩的并查集
public class UnionFind{
	private int father[] = NULL;
	public int find(int x){
		if(father[x] == x){
			return x;
		}
		return father[x] = find(father[x])   //这里实际上是一个回溯的路径压缩过程
	}
	
	public void union(int a, int b){
		int root_a = find(a);
		int root_b = find(b);
		if(root_a != root_b){
			father[root_a] = root_b;
		}
	}	
}