#include "graphedge.h"
#include "graphnode.h"
#include <memory>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

  	// STUDENT: THIS MUST BE DELETED OTHERWISE CONTRUCTOR CALLED TWICE BUT IS ANOTHER DESCTRUCTOR NEEDED
    //delete _chatBot; 
    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
// {
//     _childEdges.push_back(edge);
// }


void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
	_childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatBot)
{
    //_chatBot = chatbot;
    // this will call the move constructor
    _chatBot = std::move(chatBot); 
    //_chatBot->SetCurrentNode(this);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    //_chatBot = nullptr; // invalidate pointer at source -> chatbot now handled by stack
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    //return _childEdges[index];
    // childEdges has become a vector of smart pointers, so we need to use get to return the raw pointer from the vector
  	return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}