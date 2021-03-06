add_custom_command(OUTPUT splat.ps
                   COMMAND groff -e -T ps -man ${CMAKE_CURRENT_SOURCE_DIR}/splat.man > splat.ps
                   DEPENDS splat.man
                   COMMENT "Creating postscript file")
add_custom_target(postscript ALL
                  DEPENDS splat.ps)

# Set GROFF_NO_SGR because the following txt rule running ul is incompatible with the 
# default.
add_custom_command(OUTPUT splat.1
                   COMMAND GROFF_NO_SGR=1 && groff -e -T ascii -man ${CMAKE_CURRENT_SOURCE_DIR}/splat.man > splat.1
                   DEPENDS splat.man
                   COMMENT "Creating man page")
add_custom_target(man ALL
                  DEPENDS splat.1)

add_custom_command(OUTPUT splat.txt
                   COMMAND ul -t dumb splat.1 > splat.txt
                   DEPENDS splat.1
                   COMMENT "Creating text file")
add_custom_target(txt ALL
                  DEPENDS splat.txt)

add_custom_command(OUTPUT splat.pdf
                   COMMAND ps2pdf splat.ps > splat.pdf
                   DEPENDS splat.ps
                   COMMENT "Creating pdf file")
add_custom_target(pdf ALL
                  DEPENDS splat.pdf)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/splat.ps" DESTINATION "${DOCDIR}")
install(FILES splat.man DESTINATION "${MANDIR}/man1" RENAME splat.1)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/splat.txt" DESTINATION "${DOCDIR}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/splat.pdf" DESTINATION "${DOCDIR}")