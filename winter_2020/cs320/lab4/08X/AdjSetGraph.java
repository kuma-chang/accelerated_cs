import java.util.*;

class  AdjSetGraph<V> implements Graph<V> {
  private Map<V,Set<V>> vertices;

  // complete the implementation by adding all the methods
  // defined in the Graph interface

  // (you may also wish to add private helper methods to perform
  //  tasks that are common to several public methods)

  // Add a vertex. No-op if vertex already exists.
  public void addVertex(V v)
	{}

  // Return all the vertices 
	public Iterable<V> vertices()
	{
		return null;
	} 

  // Return the number of vertices.
	public int vertexCount()
	{
		return null;
	}

  // Answer whether a particular vertex is in the graph
	public boolean hasVertex(V v)
	{
		return null;
	}

  // Add an edge between two vertices.
  // Raises IllegalArgumentException if either vertex is not in graph
  // No-op if edge already exists
  public void addEdge(V v1,V v2) 
	{
		return null;
	}

  // Return the neighbors of a vertex
  // Raises IllegalArgumentException if vertex is not in graph
	public Iterable<V> neighbors(V v)
	{
		return null;
	}

  // Return the degree (number of neighbors) of a vertex
  // Raises IllegalArgumentException if vertex is not in graph
  public int degree(V v)
	{
		return null;
	}



  // useful for debugging, once methods are implemented
  public String toString() {
    return GraphUtils.dumpGraph(this);
  }
}
  

	
