#ifndef KMINT_UFO_TANK_HPP
#define KMINT_UFO_TANK_HPP

#include "kmint/map/map.hpp"
#include "kmint/play.hpp"
#include "kmint/primitives.hpp"

#include "kmint/ufo/state_user.hpp"

namespace kmint {
namespace ufo {

enum class tank_type { red, green };

class tank : public state_user {
public:
  tank(map::map_graph& g, map::map_node& initial_node, tank_type t);
  // wordt elke game tick aangeroepen
  void act(delta_time dt) override;

  // geeft de lengte van een zijde van de collision box van deze actor terug.
  // Belangrijk voor collision detection
  scalar collision_range() const override { return 16.0; }
  // geeft aan dat de tank andere actors kan zien
  bool perceptive() const override { return true; }
  // geeft het bereik aan waarbinnen een tank
  // andere actors kan waarnemen.
  scalar perception_range() const override { return 200.f; }

private:
  delta_time t_since_move_{};
  tank_type type_;
};

} // namespace ufo
} // namespace kmint

#endif /* KMINT_UFO_TANK_HPP */
