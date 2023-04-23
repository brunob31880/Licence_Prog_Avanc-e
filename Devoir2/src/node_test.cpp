#include "node.h"
#include <gtest/gtest.h>

using namespace mazeNode;

class NodeTest : public ::testing::Test
{
protected:
   NodeFree nodeFree;
   NodeWall nodeWall;
   NodeCheese nodeCheese;
};

TEST_F(NodeTest, GetType)
{
   EXPECT_EQ(nodeFree.getType(), NodeType_Free);
   EXPECT_EQ(nodeWall.getType(), NodeType_Wall);
   EXPECT_EQ(nodeCheese.getType(), NodeType_Cheese);
}

TEST_F(NodeTest, SetAndGetNeighbor)
{
   NodeFree neighbor1;
   NodeWall neighbor2;
   NodeCheese neighbor3;

   nodeFree.setNeighbor(NodeNeighbor_Up, &neighbor1);
   nodeFree.setNeighbor(NodeNeighbor_Down, &neighbor2);
   nodeFree.setNeighbor(NodeNeighbor_Left, &neighbor3);
   nodeFree.setNeighbor(NodeNeighbor_Right, nullptr);

   EXPECT_EQ(nodeFree.getNeighbor(NodeNeighbor_Up), &neighbor1);
   EXPECT_EQ(nodeFree.getNeighbor(NodeNeighbor_Down), &neighbor2);
   EXPECT_EQ(nodeFree.getNeighbor(NodeNeighbor_Left), &neighbor3);
   EXPECT_EQ(nodeFree.getNeighbor(NodeNeighbor_Right), nullptr);
}

TEST_F(NodeTest, IsNeighborFree)
{
   NodeFree neighbor1;
   NodeWall neighbor2;
   NodeCheese neighbor3;

   nodeFree.setNeighbor(NodeNeighbor_Up, &neighbor1);
   nodeFree.setNeighbor(NodeNeighbor_Down, &neighbor2);
   nodeFree.setNeighbor(NodeNeighbor_Left, &neighbor3);

   neighbor1.setVisited();
   EXPECT_FALSE(nodeFree.isNeighborFree(NodeNeighbor_Up));
   EXPECT_FALSE(nodeFree.isNeighborFree(NodeNeighbor_Down));
   EXPECT_TRUE(nodeFree.isNeighborFree(NodeNeighbor_Left));
   EXPECT_FALSE(nodeFree.isNeighborFree(NodeNeighbor_Right));
}

TEST_F(NodeTest, SetAndGetVisited)
{
   EXPECT_FALSE(nodeFree.isVisited());
   nodeFree.setVisited();
   EXPECT_TRUE(nodeFree.isVisited());
}

TEST_F(NodeTest, IsFreeToVisit)
{
   EXPECT_TRUE(nodeFree.isFreeToVisit());
   nodeFree.setVisited();
   EXPECT_FALSE(nodeFree.isFreeToVisit());
}

TEST_F(NodeTest, GetString)
{
   EXPECT_EQ(nodeFree.getString(), ' ');

   nodeFree.setVisited();
   EXPECT_EQ(nodeFree.getString(), '.');
   
   EXPECT_EQ(nodeWall.getString(), 'w');

   EXPECT_EQ(nodeCheese.getString(), 'c'); // Cheese should still be displayed as 'c' if it hasn't been visited
}
