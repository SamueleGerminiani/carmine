

#install third_party libraries
file(COPY ${S} DESTINATION ${IP}/carmine/lib FOLLOW_SYMLINK_CHAIN)
file(COPY ${B} DESTINATION ${IP}/carmine/lib FOLLOW_SYMLINK_CHAIN)
file(COPY ${A} DESTINATION ${IP}/carmine/lib FOLLOW_SYMLINK_CHAIN)
file(COPY ${Z} DESTINATION ${IP}/carmine/lib FOLLOW_SYMLINK_CHAIN)
