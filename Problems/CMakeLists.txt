aux_source_directory(. PROBLEMS_SOLUTIONS)
  
foreach(SOURCE ${PROBLEMS_SOLUTIONS})  
    get_filename_component(NAME "${SOURCE}" NAME_WE)  
      
    add_executable(${NAME} ${SOURCE})  
endforeach()