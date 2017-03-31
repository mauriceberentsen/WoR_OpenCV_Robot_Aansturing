#ifndef ASTAR_HPP_
#define ASTAR_HPP_

#include <iostream>
#include <iomanip>
#include <map>
#include <mutex>
#include <set>
#include <vector>

#include "Point.hpp"
#include "Size.hpp"

namespace PathAlgorithm
{
	struct Vertex
	{
			/**
			 *
			 */
			Vertex(	double anX,
					double anY
					) :
						name(""),
						phi1( anX),
						phi2( anY),
						phi3(0),
						actualCost( 0.0),
						heuristicCost( 0.0)
			{
			}

			Vertex(	std::string aName,
					double anPh1,
					double anPh2,
					double anPh3
					) :
						name(aName),
						phi1(anPh1),
						phi2(anPh2),
						phi3(anPh3),
						actualCost( 0.0),
						heuristicCost( 0.0)
			{
			}
			Vertex(	std::string aName,
					double anX,
					double anY
					) :
						name(aName),
						phi1( anX),
						phi2( anY),
						phi3( 42),
						actualCost( 0.0),
						heuristicCost( 0.0)
			{
			}
/*
			Vertex(	std::string aName,
					double anX,
					double anY,
					int cost
					) :
						name(aName),
						phi1( anX),
						phi2( anY),
						phi3(66),
						actualCost( cost),
						heuristicCost( 0.0)
			{
			}*/
			/**
			 *
			 */
			Vertex(const Point& aPoint) :
				name(""),
				phi1( aPoint.x),
				phi2( aPoint.y),
				phi3(0),
				actualCost( 0.0),
				heuristicCost( 0.0)
			{
			}

			Vertex(std::string aName,const Point& aPoint) :
				name(""),
				phi1( aPoint.x),
				phi2( aPoint.y),
				phi3(0),
				actualCost( 0.0),
				heuristicCost( 0.0)
			{
			}
			/**
			 *
			 */
			Point asPoint() const
			{
				return Point( phi1, phi2);
			}
			/**
			 *
			 */
			bool lessCost( const Vertex& aVertex) const
			{
				if (heuristicCost < aVertex.heuristicCost)
					return true;
				// less uncertainty if the actual cost is smaller
				if (heuristicCost == aVertex.heuristicCost)
					return actualCost > aVertex.actualCost;
				return false;
			}
			/**
			 *
			 */
			bool lessId( const Vertex& aVertex) const
			{
/*				if(phi1 < aVertex.phi1 && phi2 < aVertex.phi2) return true;
				//if(phi1 < aVertex.phi1) return true;
				//if(phi1 == aVertex.phi1) return phi2 < aVertex.phi2;
				if(phi1 == aVertex.phi1 && phi2 == aVertex.phi2) return phi3 < aVertex.phi3;
				*/
				if(phi1 < aVertex.phi1) return true;
				if(phi1 == aVertex.phi1){
					if(phi2 == aVertex.phi2){
						return phi3 < aVertex.phi3;
					}
					return phi2 < aVertex.phi2;
				}
				return false;

			}

			/**
			 *
			 */
			bool equalPoint( const Vertex& aVertex) const
			{
			//std::cout<<std::setprecision(1)<<std::fixed<<aVertex.phi1 << "==" << phi1 << ";"<<aVertex.phi2 << "==" << phi2 << ";"<<aVertex.phi3 << "==" << phi3 << ";" <<std::endl ;
				return phi1 == aVertex.phi1 && phi2 == aVertex.phi2 && phi3 == aVertex.phi3;
			}

			std::string name;
			double phi1;
			double phi2;
			double phi3;

			double actualCost;
			double heuristicCost;
	};
	// struct Vertex

	/**
	 *
	 */
	struct VertexLessCostCompare
	{
			bool operator()(	const Vertex& lhs,
								const Vertex& rhs) const
			{
				return lhs.lessCost( rhs);
			}
	};
	// struct VertexCostCompare
	/**
	 *
	 */
	struct VertexLessIdCompare
	{
			bool operator()(	const Vertex& lhs,
								const Vertex& rhs) const
			{
				return lhs.lessId( rhs);
			}
	};
	// struct VertexIdCompare
	/**
	 *
	 */
	struct VertexEqualPointCompare
	{
			bool operator()(	const Vertex& lhs,
								const Vertex& rhs) const
			{
				return lhs.equalPoint( rhs);
			}
	};
	// struct VertexPointCompare
	struct Edge
	{
			Edge(	const Vertex& aVertex1,
					const Vertex& aVertex2,
					int aCost = 0) :
						vertex1( aVertex1),
						vertex2( aVertex2),
						cost(aCost)
			{
			}
			Edge( const Edge& anEdge,int aCost) :
				vertex1( anEdge.vertex1),
				vertex2( anEdge.vertex2),
				cost(aCost)
			{
			}

			const Vertex& thisSide( const Vertex& aVertex) const
			{
				if (vertex1.equalPoint( aVertex))
					return vertex1;
				if (vertex2.equalPoint( aVertex))
					return vertex2;
				throw std::logic_error( "thisSide: huh???");
			}

			const Vertex& otherSide( const Vertex& aVertex) const
			{
				if (vertex1.equalPoint( aVertex))
					return vertex2;
				if (vertex2.equalPoint( aVertex))
					return vertex1;
				throw std::logic_error( "otherSide: huh???");
			}

			Vertex vertex1;
			Vertex vertex2;
			int cost;
	}; // struct Edge
	/**
	 *
	 * @param os
	 * @param aVertex
	 * @return
	 */
	inline std::ostream& operator<<( 	std::ostream& os,
										const Vertex & aVertex)
	{
		return os << aVertex.name<<": " << "(" << aVertex.phi1 << "," << aVertex.phi2 << "," << aVertex.phi3 << "), " << aVertex.actualCost << " " << aVertex.heuristicCost;
	}
	/**
	 *
	 * @param os
	 * @param anEdge
	 * @return
	 */
	inline std::ostream& operator<<( 	std::ostream& os,
										const Edge& anEdge)
	{
		return os << anEdge.vertex1 << " -> " << anEdge.vertex2  << " edge_cost: "<< anEdge.cost ;
	}
	/*
	 *
	 */
	typedef std::vector< Vertex > Path;
	typedef std::vector< Vertex > OpenSet;
	typedef std::set< Vertex, VertexLessIdCompare > ClosedSet;
	typedef std::map< Vertex, Vertex, VertexLessIdCompare > VertexMap;
	/**
	 *
	 */
	class AStar
	{
		public:
			/**
			 *
			 */
			Path search(const Point& aStartPoint,
						const Point& aGoalPoint,
						std::vector<Edge> edges
						/*const Size& aRobotSize*/);
			/**
			 *
			 */
			Path search(Vertex aStart,
						const Vertex& aGoal,
						std::vector<Edge> edges
						/*const Size& aRobotSize*/);
			/**
			 *
			 */
			void addToOpenSet( const Vertex& aVertex);
			/**
			 *
			 */
			void removeFromOpenSet( const Vertex& aVertex);
			/**
			 *
			 */
			void removeFromOpenSet( OpenSet::iterator& i);
			/**
			 *
			 */
			OpenSet::iterator findInOpenSet( const Vertex& aVertex);

			Vertex& findInOpenSetbyName(std::string vertexName);
			/**
			 *
			 */
			bool findRemoveInOpenSet( const Vertex& aVertex);
			/**
			 *
			 */
			void removeFirstFromOpenSet();
			/**
			 *
			 */
			void addToClosedSet( const Vertex& aVertex);
			/**
			 *
			 */
			void removeFromClosedSet( const Vertex& aVertex);
			/**
			 *
			 */
			void removeFromClosedSet( ClosedSet::iterator& i);
			/**
			 *
			 */
			ClosedSet::iterator findInClosedSet( const Vertex& aVertex);
			/**
			 *
			 */
			bool findRemoveClosedSet( const Vertex& aVertex);
			/**
			 *
			 */
			ClosedSet getClosedSet() const;
			/**
			 *
			 */
			OpenSet getOpenSet() const;
			/**
			 *
			 */
			VertexMap getPredecessorMap() const;

		protected:
			/**
			 *
			 */
			ClosedSet& getCS();
			/**
			 *
			 */
			const ClosedSet& getCS() const;
			/**
			 *
			 */
			OpenSet& getOS();
			/**
			 *
			 */
			const OpenSet& getOS() const;
			/**
			 *
			 */
			VertexMap& getPM();
			/**
			 *
			 */
			const VertexMap& getPM() const;

		private:
			/**
			 *
			 */
			ClosedSet closedSet;
			/**
			 *
			 */
			OpenSet openSet;
			/**
			 *
			 */
			VertexMap predecessorMap;

			mutable std::recursive_mutex openSetMutex;
			mutable std::recursive_mutex closedSetMutex;
			mutable std::recursive_mutex predecessorMapMutex;

	}; // class AStar
} // namespace PathAlgorithm
#endif // ASTAR_HPP_
