#Parse command-line options
PARAMS=$(getopt -o h,d: --long help,winmanager:,display: -n "testWindow.sh" -- "$@")

eval set -- "$PARAMS"

while true
do
    case "$1" in

    -h | --help)
        echo "USAGE : testWindow.sh --winmanager [some binary] --display [1-9]"
        exit 0
        ;;

    -d | --display)
        DISPLAY_NUM="$2"
        shift 2
        ;;

    --winmanager)
        WIN_MANAGER="$2"
        shift 2
        ;;

    --)
        shift
        if [[ ! $WIN_MANAGER ]]; then
            echo "[ERROR] : Missing window manager."
            echo "USAGE : testWindow.sh --winmanager [some binary] --display [1-9]"
            exit 1
        elif [[ ! $DISPLAY_NUM ]]; then
            echo "[ERROR] : Missing display number."
            echo "USAGE : testWindow.sh --winmanager [some binary] --display [1-9]"
            exit 1
        fi

        #End of parsing
        break
        ;;
    *)
        echo "[ERROR] : No such option $1."
        exit 1
        ;;
    esac
done

Xephyr :"$DISPLAY_NUM" -screen 1280x720 -ac &
DISPLAY=:"$DISPLAY_NUM" "$WIN_MANAGER"