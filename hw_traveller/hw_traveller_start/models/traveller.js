const Traveller = function(journeys) {
  this.journeys = journeys;
};

Traveller.prototype.getJourneyStartLocations = function() {
  const start = this.journeys.map((journey) => {
    return journey.startLocation;
  });
  return start;
};

Traveller.prototype.getJourneyEndLocations = function () {
  const end = this.journeys.map((journey) => {
    return journey.endLocation;
  });
  return end;
};

Traveller.prototype.getJourneysByTransport = function (transport) {
  const journeyByTransport = this.journeys.filter((journey) => {
    return journey.transport;
  });
  return journeyByTransport;
};

Traveller.prototype.getJourneysByMinDistance = function (minDistance) {
  const minDistance = this.journeys.reduce(function () {

  })
};

Traveller.prototype.calculateTotalDistanceTravelled = function () {
  const totalDistance = this.journeys.reduce(function(totalDistance,currentDistance) {
    return totalDistance += currentDistance.distance;
  }, 0);
};

// Traveller.prototype.getUniqueModesOfTransport = function () {

// };


module.exports = Traveller;
