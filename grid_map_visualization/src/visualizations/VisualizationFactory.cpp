/*
 * VisualizationFactory.cpp
 *
 *  Created on: Mar 20, 2015
 *      Author: Péter Fankhauser
 *   Institute: ETH Zurich, Autonomous Systems Lab
 */

#include <grid_map_visualization/visualizations/VisualizationFactory.hpp>
#include <grid_map_visualization/visualizations/PointCloudVisualization.hpp>
#include <grid_map_visualization/visualizations/VectorVisualization.hpp>
#include <grid_map_visualization/visualizations/OccupancyGridVisualization.hpp>
#include <grid_map_visualization/visualizations/GridCellsVisualization.hpp>
#include <grid_map_visualization/visualizations/MapRegionVisualization.hpp>
#include <grid_map_visualization/visualizations/SemanticLabelsVisualization.hpp>
#include <grid_map_visualization/visualizations/TerrainMapVisualization.hpp>

// STL
#include <algorithm>

namespace grid_map_visualization {

VisualizationFactory::VisualizationFactory(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
  types_.push_back("point_cloud");
  types_.push_back("vectors");
  types_.push_back("occupancy_grid");
  types_.push_back("grid_cells");
  types_.push_back("map_region");
  types_.push_back("semantic_labels");
  types_.push_back("terrain_map");
}

VisualizationFactory::~VisualizationFactory()
{
}

bool VisualizationFactory::isValidType(const std::string& type)
{
  return end(types_) != std::find(begin(types_), end(types_), type);
}

std::shared_ptr<VisualizationBase> VisualizationFactory::getInstance(const std::string& type,
                                                                     const std::string& name)
{
  // TODO: Make this nicer: http://stackoverflow.com/questions/9975672/c-automatic-factory-registration-of-derived-types
  if (type == "point_cloud") return std::shared_ptr<VisualizationBase>(new PointCloudVisualization(nodeHandle_, name));
  if (type == "vectors") return std::shared_ptr<VisualizationBase>(new VectorVisualization(nodeHandle_, name));
  if (type == "occupancy_grid") return std::shared_ptr<VisualizationBase>(new OccupancyGridVisualization(nodeHandle_, name));
  if (type == "grid_cells") return std::shared_ptr<VisualizationBase>(new GridCellsVisualization(nodeHandle_, name));
  if (type == "map_region") return std::shared_ptr<VisualizationBase>(new MapRegionVisualization(nodeHandle_, name));
  if (type == "semantic_labels") return std::shared_ptr<VisualizationBase>(new SemanticLabelsVisualization(nodeHandle_, name));
  if (type == "terrain_map") return std::shared_ptr<VisualizationBase>(new TerrainMapVisualization(nodeHandle_, name));
  return std::shared_ptr<VisualizationBase>();
}

} /* namespace grid_map_visualization */
