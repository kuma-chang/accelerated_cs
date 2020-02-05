import java.util.*;

class  AdjSetGraph<V> implements Graph<V> {
  private Map<V,Set<V>> vertices = new HashMap<V, Set<V>>();

  // complete the implementation by adding all the methods
  // defined in the Graph interface

  // (you may also wish to add private helper methods to perform
  //  tasks that are common to several public methods)

  // Add a vertex. No-op if vertex already exists.
  public void addVertex(V v)
	{
		if(vertices.containsKey(v))
		{
			System.out.println(v + "->Vertex already exist");
			return;
		}
		else
		{
		  Set<V> temp = new HashSet<V>();
			this.vertices.put(v, temp);
			return;
		}
	}


  // Return all the vertices 
	public Iterable<V> vertices()
	{
		Set<V> temp = vertices.keySet();
		return temp;
	} 

  // Return the number of vertices.
	public int vertexCount()
	{
		Set<V> temp = vertices.keySet();
		int count = temp.size();
		return count; 
	}

  // Answer whether a particular vertex is in the graph
	public boolean hasVertex(V v)
	{
		return vertices.containsKey(v);
	}

  // Add an edge between two vertices.
  // Raises IllegalArgumentException if either vertex is not in graph
  // No-op if edge already exists
  public void addEdge(V v1,V v2) 
	{
		Set<V> temp = vertices.keySet();
		Set<V> neighbors_1 = vertices.get(v1);
		Set<V> neighbors_2 = vertices.get(v2);
		if(!temp.contains(v1) && !temp.contains(v2))
			throw new IllegalArgumentException("either vertex is not in graph");
		else if(neighbors_1.contains(v2) && neighbors_2.contains(v1))
			return;
		else
		{
			neighbors_1.add(v2);
			neighbors_2.add(v1);
		}
	}

  // Return the neighbors of a vertex
  // Raises IllegalArgumentException if vertex is not in graph
	public Iterable<V> neighbors(V v)
	{
		Set<V> temp = vertices.keySet();
		if(temp.contains(v))
		{
			Set<V> neighbors = vertices.get(v);
			return neighbors;
		}
		else
			throw new IllegalArgumentException("vertex is not in graph");
	}

  // Return the degree (number of neighbors) of a vertex
  // Raises IllegalArgumentException if vertex is not in graph
  public int degree(V v)
	{
		Set<V> temp = vertices.keySet();
		if(temp.contains(v))
		{
			Set<V> neighbors = vertices.get(v);
			int count = neighbors.size();
			return count; 
		}
		else
			throw new IllegalArgumentException("vertex is not in graph");
	}



	// useful for debugging, once methods are implemented
	public String toString() {
		return GraphUtils.dumpGraph(this);
	}
}



