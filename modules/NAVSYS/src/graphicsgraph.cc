/**
* \file      graphicsgraph.cc
* \brief     graphs in sfmlgraphics window
* \author    Leo Jenneskens
* \copyright Copyright (c) 2017, The R2D2 Team
* \license   See LICENSE
*/
#include "graphicsgraph.hh" 

void GraphDrawer::draw(){	 
	
	for(auto it = graphNodes.begin(); it != graphNodes.end(); ++it) {
		it->draw(window);
	}
	for(auto it = graphVertices.begin(); it != graphVertices.end(); ++it) {
		it->draw(window);
	}
	while (window.isOpen()) {
			
		window.display();
		sf::sleep( sf::milliseconds( 60 ));
		sf::Event event;
		while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}
	}
}

void GraphDrawer::reload(Graph * g){

	clear();
	std::vector<Node> nodeVector = g->getNodes();	
	for(auto it = nodeVector.begin(); it != nodeVector.end(); ++it) {
		graphNodes.push_back(GraphNode(sf::Vector2f(it->getCoordinate().x*100,it->getCoordinate().y*100)));
	}
	std::vector<Vertice> verticeVector = g->getVertices();	
	for(auto it = verticeVector.begin(); it != verticeVector.end(); ++it) {
		graphVertices.push_back(GraphVertice(sf::Vector2f(it->getCurrent()->getCoordinate().x*100,it->getCurrent()->getCoordinate().y*100),sf::Vector2f(it->getNeighbour()->getCoordinate().x*100,it->getNeighbour()->getCoordinate().y*100)));     
	}
}

void GraphDrawer::clear(){
	graphNodes.clear();
	graphVertices.clear();
}