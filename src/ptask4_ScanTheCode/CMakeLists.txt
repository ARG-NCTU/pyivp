SET(SRC
  Detector.cpp
  FindColor.cpp
  LightBuoyDetector.cpp
  )

SET(HEADERS
  Detector.h
  FindColor.h
  LightBuoyDetector.h
  feature.h
  types.h
  transformations.h
  utils.h
)

# Build Library
ADD_LIBRARY(task4 ${SRC})

# TARGET_LINK_LIBRARIES( task4

#    mbutil
#    )

