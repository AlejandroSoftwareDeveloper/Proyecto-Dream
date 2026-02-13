set windows-shell := ["CMD","/c"]

# Execute build with gprbuild
build:
    @echo "***   BUILDING   ***"
    @gprbuild
    @echo "*** FINISH BUILD ***"

# Check gprbuild is install
gpr_is_install:
    @echo "***   SEARCHING GPRBUILD  ***"
    @gprbuild --version
    @echo "***   END SEARCH GPRBUILD ***\n"


# Check gprbuild is install
gnat_is_install:
    @echo "***   SEARCHING GNAT ***"
    @gnat --version
    @echo "***   END SEARCH GNAT ***\n"


# Check tools are install
check_tools: gpr_is_install gnat_is_install
