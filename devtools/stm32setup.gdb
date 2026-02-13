set mem inaccessible-by-default off
shell killall ST-LINK_gdbserver st-util

define connect
        shell ST-LINK_gdbserver -c devtools/config.txt & sleep 2
        shell echo st-util -p 4242 & sleep 2
	target remote :4242
end

define simple-reset
       monitor reset
       monitor halt
end

define reset
       simple-reset
       tbreak main
       continue
end

define hook-run
       reset
end

define hookpost-load
       reset
end

define hookpost-quit
       shell killall ST-LINK_gdbserver st-util
end

connect
reset
