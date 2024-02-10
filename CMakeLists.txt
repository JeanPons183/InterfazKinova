#------------------------ Setup Cmake and QT directories -------------------------

cmake_minimum_required(VERSION 3.5)

project(KinovaGen3Lite VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR   ON)
set(CMAKE_VERBOSE_MAKEFILE      ON)
set(CMAKE_COLOR_MAKEFILE        ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Gui)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

#------------------------ Executable Setup -------------------------

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(KinovaGen3LiteApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        thirdParty/argh/assets/argh_logo.png thirdParty/argh/assets/argh_logo_small.png thirdParty/argh/test_package/BUCK thirdParty/argh/test_package/CMakeLists.txt thirdParty/argh/test_package/conanfile.py  thirdParty/argh/argh-config.cmake thirdParty/argh/argh.h  thirdParty/argh/BUCK thirdParty/argh/CMakeLists.txt thirdParty/argh/CODE_OF_CONDUCT.md thirdParty/argh/conanfile.py thirdParty/argh/doctest.h  thirdParty/argh/LICENSE thirdParty/argh/README.md
        kortex_api/include/client/FrameHandler.h kortex_api/include/client/IRouterClient.h kortex_api/include/client/ITransportClient.h kortex_api/include/client/NotificationHandler.h kortex_api/include/client/RouterClient.h kortex_api/include/client/SessionManager.h kortex_api/include/client/TransportClientTcp.h kortex_api/include/client/TransportClientUdp.h kortex_api/include/client/version.h kortex_api/include/client_stubs/ActuatorConfigClientRpc.h kortex_api/include/client_stubs/ActuatorCyclicClientRpc.h kortex_api/include/client_stubs/BaseClientRpc.h kortex_api/include/client_stubs/BaseCyclicClientRpc.h kortex_api/include/client_stubs/ControlConfigClientRpc.h kortex_api/include/client_stubs/DeviceConfigClientRpc.h kortex_api/include/client_stubs/DeviceManagerClientRpc.h kortex_api/include/client_stubs/GripperCyclicClientRpc.h kortex_api/include/client_stubs/InterconnectConfigClientRpc.h kortex_api/include/client_stubs/InterconnectCyclicClientRpc.h kortex_api/include/client_stubs/SessionClientRpc.h kortex_api/include/client_stubs/TestClientRpc.h kortex_api/include/client_stubs/VisionConfigClientRpc.h kortex_api/include/common/Frame.h kortex_api/include/common/HeaderInfo.h kortex_api/include/common/KBasicException.h kortex_api/include/common/KDetailedException.h kortex_api/include/common/KError.h kortex_api/include/common/KinovaTcpUtilities.h kortex_api/include/common/TransportBridgeDummy.h kortex_api/include/common/version.h kortex_api/include/google/protobuf/compiler/cpp/cpp_generator.h kortex_api/include/google/protobuf/compiler/csharp/csharp_generator.h kortex_api/include/google/protobuf/compiler/csharp/csharp_names.h kortex_api/include/google/protobuf/compiler/java/java_generator.h kortex_api/include/google/protobuf/compiler/java/java_names.h kortex_api/include/google/protobuf/compiler/javanano/javanano_generator.h kortex_api/include/google/protobuf/compiler/js/js_generator.h kortex_api/include/google/protobuf/compiler/js/well_known_types_embed.h kortex_api/include/google/protobuf/compiler/objectivec/objectivec_generator.h kortex_api/include/google/protobuf/compiler/objectivec/objectivec_helpers.h kortex_api/include/google/protobuf/compiler/php/php_generator.h kortex_api/include/google/protobuf/compiler/python/python_generator.h kortex_api/include/google/protobuf/compiler/ruby/ruby_generator.h kortex_api/include/google/protobuf/compiler/code_generator.h kortex_api/include/google/protobuf/compiler/command_line_interface.h kortex_api/include/google/protobuf/compiler/importer.h kortex_api/include/google/protobuf/compiler/parser.h kortex_api/include/google/protobuf/compiler/plugin.h kortex_api/include/google/protobuf/compiler/plugin.pb.h kortex_api/include/google/protobuf/io/coded_stream.h kortex_api/include/google/protobuf/io/gzip_stream.h kortex_api/include/google/protobuf/io/printer.h kortex_api/include/google/protobuf/io/strtod.h kortex_api/include/google/protobuf/io/tokenizer.h kortex_api/include/google/protobuf/io/zero_copy_stream.h kortex_api/include/google/protobuf/io/zero_copy_stream_impl.h kortex_api/include/google/protobuf/io/zero_copy_stream_impl_lite.h kortex_api/include/google/protobuf/stubs/atomic_sequence_num.h kortex_api/include/google/protobuf/stubs/atomicops.h kortex_api/include/google/protobuf/stubs/atomicops_internals_arm64_gcc.h kortex_api/include/google/protobuf/stubs/atomicops_internals_arm_gcc.h kortex_api/include/google/protobuf/stubs/atomicops_internals_arm_qnx.h kortex_api/include/google/protobuf/stubs/atomicops_internals_generic_c11_atomic.h kortex_api/include/google/protobuf/stubs/atomicops_internals_generic_gcc.h kortex_api/include/google/protobuf/stubs/atomicops_internals_mips_gcc.h kortex_api/include/google/protobuf/stubs/atomicops_internals_power.h kortex_api/include/google/protobuf/stubs/atomicops_internals_ppc_gcc.h kortex_api/include/google/protobuf/stubs/atomicops_internals_solaris.h kortex_api/include/google/protobuf/stubs/atomicops_internals_tsan.h kortex_api/include/google/protobuf/stubs/atomicops_internals_x86_gcc.h kortex_api/include/google/protobuf/stubs/atomicops_internals_x86_msvc.h kortex_api/include/google/protobuf/stubs/bytestream.h kortex_api/include/google/protobuf/stubs/callback.h kortex_api/include/google/protobuf/stubs/casts.h kortex_api/include/google/protobuf/stubs/common.h kortex_api/include/google/protobuf/stubs/fastmem.h kortex_api/include/google/protobuf/stubs/hash.h kortex_api/include/google/protobuf/stubs/logging.h kortex_api/include/google/protobuf/stubs/macros.h kortex_api/include/google/protobuf/stubs/mutex.h kortex_api/include/google/protobuf/stubs/once.h kortex_api/include/google/protobuf/stubs/platform_macros.h kortex_api/include/google/protobuf/stubs/port.h kortex_api/include/google/protobuf/stubs/scoped_ptr.h kortex_api/include/google/protobuf/stubs/shared_ptr.h kortex_api/include/google/protobuf/stubs/singleton.h kortex_api/include/google/protobuf/stubs/status.h kortex_api/include/google/protobuf/stubs/stl_util.h kortex_api/include/google/protobuf/stubs/stringpiece.h kortex_api/include/google/protobuf/stubs/template_util.h kortex_api/include/google/protobuf/stubs/type_traits.h kortex_api/include/google/protobuf/util/delimited_message_util.h kortex_api/include/google/protobuf/util/field_comparator.h kortex_api/include/google/protobuf/util/field_mask_util.h kortex_api/include/google/protobuf/util/json_util.h kortex_api/include/google/protobuf/util/message_differencer.h kortex_api/include/google/protobuf/util/time_util.h kortex_api/include/google/protobuf/util/type_resolver.h kortex_api/include/google/protobuf/util/type_resolver_util.h kortex_api/include/google/protobuf/any.h kortex_api/include/google/protobuf/any.pb.h kortex_api/include/google/protobuf/api.pb.h kortex_api/include/google/protobuf/arena.h kortex_api/include/google/protobuf/arena_impl.h kortex_api/include/google/protobuf/arenastring.h kortex_api/include/google/protobuf/descriptor.h kortex_api/include/google/protobuf/descriptor.pb.h kortex_api/include/google/protobuf/descriptor_database.h kortex_api/include/google/protobuf/duration.pb.h kortex_api/include/google/protobuf/dynamic_message.h kortex_api/include/google/protobuf/empty.pb.h kortex_api/include/google/protobuf/extension_set.h kortex_api/include/google/protobuf/field_mask.pb.h kortex_api/include/google/protobuf/generated_enum_reflection.h kortex_api/include/google/protobuf/generated_enum_util.h kortex_api/include/google/protobuf/generated_message_reflection.h kortex_api/include/google/protobuf/generated_message_table_driven.h kortex_api/include/google/protobuf/generated_message_util.h kortex_api/include/google/protobuf/has_bits.h kortex_api/include/google/protobuf/map.h kortex_api/include/google/protobuf/map_entry.h kortex_api/include/google/protobuf/map_entry_lite.h kortex_api/include/google/protobuf/map_field.h kortex_api/include/google/protobuf/map_field_inl.h kortex_api/include/google/protobuf/map_field_lite.h kortex_api/include/google/protobuf/map_type_handler.h kortex_api/include/google/protobuf/message.h kortex_api/include/google/protobuf/message_lite.h kortex_api/include/google/protobuf/metadata.h kortex_api/include/google/protobuf/metadata_lite.h kortex_api/include/google/protobuf/reflection.h kortex_api/include/google/protobuf/reflection_ops.h kortex_api/include/google/protobuf/repeated_field.h kortex_api/include/google/protobuf/service.h kortex_api/include/google/protobuf/source_context.pb.h kortex_api/include/google/protobuf/struct.pb.h kortex_api/include/google/protobuf/text_format.h kortex_api/include/google/protobuf/timestamp.pb.h kortex_api/include/google/protobuf/type.pb.h kortex_api/include/google/protobuf/unknown_field_set.h kortex_api/include/google/protobuf/wire_format.h kortex_api/include/google/protobuf/wire_format_lite.h kortex_api/include/google/protobuf/wire_format_lite_inl.h kortex_api/include/google/protobuf/wrappers.pb.h kortex_api/include/messages/ActuatorConfig.pb.h kortex_api/include/messages/ActuatorCyclic.pb.h kortex_api/include/messages/Base.pb.h kortex_api/include/messages/BaseCyclic.pb.h kortex_api/include/messages/Common.pb.h kortex_api/include/messages/ControlConfig.pb.h kortex_api/include/messages/DeviceConfig.pb.h kortex_api/include/messages/DeviceManager.pb.h kortex_api/include/messages/Errors.pb.h kortex_api/include/messages/Frame.pb.h kortex_api/include/messages/GripperConfig.pb.h kortex_api/include/messages/GripperCyclic.pb.h kortex_api/include/messages/GripperCyclicMessage.pb.h kortex_api/include/messages/InterconnectConfig.pb.h kortex_api/include/messages/InterconnectCyclic.pb.h kortex_api/include/messages/InterconnectCyclicMessage.pb.h kortex_api/include/messages/ProductConfiguration.pb.h kortex_api/include/messages/Session.pb.h kortex_api/include/messages/Test.pb.h kortex_api/include/messages/VisionConfig.pb.h kortex_api/lib/release/libKortexApiCpp.a kortex_api/lib/release/libKortexApiCpp_without_protobuf.a
        Gen3lite_model.h mat.h
        kinovarobot.h kinovarobot.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET KinovaGen3Lite APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(KinovaGen3Lite SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(KinovaGen3Lite
            ${PROJECT_SOURCES}
        )
    endif()
endif()

#------------------------ Setup MSVC ------------------------------

set (CMAKE_CXX_STANDARD 11)

macro(configure_msvc_runtime)

    # Default to statically-linked runtime.
    if("${MSVC_RUNTIME}" STREQUAL "")
      set(MSVC_RUNTIME "static")
    endif()

    # Set compiler options.
    set(variables
      CMAKE_C_FLAGS_DEBUG
      CMAKE_C_FLAGS_MINSIZEREL
      CMAKE_C_FLAGS_RELEASE
      CMAKE_C_FLAGS_RELWITHDEBINFO
      CMAKE_CXX_FLAGS_DEBUG
      CMAKE_CXX_FLAGS_MINSIZEREL
      CMAKE_CXX_FLAGS_RELEASE
      CMAKE_CXX_FLAGS_RELWITHDEBINFO
    )

    if(${MSVC_RUNTIME} STREQUAL "static")
      message(STATUS
        "MSVC -> forcing use of statically-linked runtime."
      )
      foreach(variable ${variables})
        if(${variable} MATCHES "/MD")
          string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
        endif()
      endforeach()

    else()
      message(STATUS
        "MSVC -> forcing use of dynamically-linked runtime."
      )
      foreach(variable ${variables})
        if(${variable} MATCHES "/MT")
          string(REGEX REPLACE "/MT" "/MD" ${variable} "${${variable}}")
        endif()
      endforeach()

    endif()

endmacro()

#include_directories(${PROJECT_SOURCE_DIR}/thirdParty/cxxopts/)

configure_msvc_runtime()

if(UNIX)
  add_definitions(-D_OS_UNIX)
else()
  MESSAGE(FATAL_ERROR "Unknown os! Not supported yet")
endif()

#------------------------ Setup Kortex Api Path and Libraries -------------------------

target_link_libraries(KinovaGen3LiteApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(KinovaGen3LiteApp PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(KinovaGen3LiteApp PRIVATE Qt${QT_VERSION_MAJOR}::Gui)

if(NOT KORTEX_SUB_DIR)
  set(KORTEX_SUB_DIR "")
else()
  set(KORTEX_SUB_DIR "${KORTEX_SUB_DIR}/")
endif()

set(KORTEX_DIR "${PROJECT_SOURCE_DIR}/kortex_api/${KORTEX_SUB_DIR}")

link_libraries(${KORTEX_DIR}lib/release/libKortexApiCpp.a)
target_link_libraries(KinovaGen3LiteApp PUBLIC ${KORTEX_DIR}lib/release/libKortexApiCpp.a)

# Add Include Directories
target_include_directories(KinovaGen3LiteApp PUBLIC ${KORTEX_DIR}include)
target_include_directories(KinovaGen3LiteApp PUBLIC ${KORTEX_DIR}include/client)
target_include_directories(KinovaGen3LiteApp PUBLIC ${KORTEX_DIR}include/common)
target_include_directories(KinovaGen3LiteApp PUBLIC ${KORTEX_DIR}include/messages)
target_include_directories(KinovaGen3LiteApp PUBLIC ${KORTEX_DIR}include/client_stubs)

link_libraries(pthread)

include_directories(${PROJECT_SOURCE_DIR}/thirdParty/argh)

#------------------------ Executable Finalize -------------------------

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.KinovaGen3Lite)
endif()
set_target_properties(KinovaGen3LiteApp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS KinovaGen3LiteApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_finalize_executable(KinovaGen3LiteApp)
endif()
#---------------------------------------------------------------------------------
