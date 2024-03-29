const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Wi-Fi Audio Control</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.min.js"></script>
    <link
        href="data:image/x-icon;base64,AAABAAEAEBAQAAEABAAoAQAAFgAAACgAAAAQAAAAIAAAAAEABAAAAAAAgAAAAAAAAAAAAAAAEAAAAAAAAAAAAAAA/4QAAHNoXQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEAAAAAACIgERAiIiIAAAABAAAAAAAAAAAAAAAAAAAAAAABAAAAIiIiIBEQIgAAAAAAAQAAAAAAAAAAAAAAAAAAAQAAAAAiIiARECIiAAAAAAEAAAAAAAAAAAAAAAAAAAAAAAAQACIiIiIiAREAAAAAAAAAEAAAAAAAAAAAD9/wAAiIEAAP3/AAD//wAA/98AAICJAAD/3wAA//8AAP9/AACCIQAA/38AAP//AAD/+wAAgBEAAP/7AAD//wAA"
        rel="icon" type="image/x-icon" />

    <script>

        function changeBassGain(slider) {

            var sync = $('#sync').is(":checked");

            if (sync) {
                if (slider.id === 'left') {
                    $('#right').val($('#left').val());
                } else if (slider.id === 'right') {
                    $('#left').val($('#right').val());
                }
            }

            $.post("/setBass",
                {
                    left: $('#left').val(),
                    right: $('#right').val()
                },
                function (data, status) {
                    console.log("Data: " + data + "\nStatus: " + status);
                }
            );
        }

        function changeEq(slider) {

            $.post("/setEq",
                {
                    band: $(slider).attr("data-band"),
                    eqval: $(slider).val()
                },
                function (data, status) {
                    console.log("Data: " + data + "\nStatus: " + status);
                }
            );
        }

        $(document).ready(function () {
            $.get("/getEq",
                function (data, status) {
                    if (status === "success") {
                        $('#eq0').val(parseFloat(data.band0));
                        $('#eq1').val(parseFloat(data.band1));
                        $('#eq2').val(parseFloat(data.band2));
                        $('#eq3').val(parseFloat(data.band3));
                        $('#eq4').val(parseFloat(data.band4));
                        $('#eq5').val(parseFloat(data.band5));
                        $('#eq6').val(parseFloat(data.band6));
                        $('#eq7').val(parseFloat(data.band7));
                        $('#eq8').val(parseFloat(data.band8));
                        $('#eq9').val(parseFloat(data.band9));
                    }
                }
            );

            $.get("/getBass",
                function (data, status) {
                    if (status === "success") {
                        $('#left').val(parseInt(data.bassleft));
                        $('#right').val(parseInt(data.bassright));
                    }
                }
            );
        });

    </script>

</head>

<body>

    <div class="container-fluid pt-3">
        <div class="card">
            <div class="card-body custom-control custom-switch">
                <h4 class="card-title">Skhome</h3>
        <div class="card">
            <div class="card-body custom-control custom-switch">
                <h4 class="card-title">Bass Control</h4>
        <div class="card">
            <div class="card-body custom-control custom-switch">
                <h4 class="card-title">Bass Control</h4>

                <div class="form-check-inline">
                    <input type="range" name="left" id="left" min="0" max="65" value="30"
                        onchange="changeBassGain(this);" class="custom-range">&nbsp;
                    <input type="checkbox" name="sync" id="sync" checked class="form-check-input">
                    <input type="range" name="right" id="right" min="0" max="65" value="30"
                        onchange="changeBassGain(this);" class="custom-range">
                </div>
            </div>
        </div>

        <br />
        <div class="card">
            <div class="card-body custom-control custom-switch">
                <h4 class="card-title">Equalizer</h4>

                <input type="range" name="eq0" id="eq0" min="0" max="48" value="24" step="1"
                    onchange="changeEq(this);" class="custom-range" data-band="0">&nbsp;32&nbsp;hz

                <input type="range" name="eq1" id="eq1" min="0" max="48" value="24" step="1"
                    onchange="changeEq(this);" class="custom-range" data-band="1">&nbsp;64&nbsp;hz

                <input type="range" name="eq2" id="eq2" min="0" max="48" value="24" step="1"
                    onchange="changeEq(this);" class="custom-range" data-band="2">&nbsp;125&nbsp;hz

                <input type="range" name="eq3" id="eq3" min="0" max="48" value="24" step="1"
                    onchange="changeEq(this);" class="custom-range" data-band="3">&nbsp;250&nbsp;hz

                <input type="range" name="eq4" id="eq4" min="0" max="48" value="24" step="1"
                    onchange="changeEq(this);" class="custom-range" data-band="4">&nbsp;500&nbsp;hz

                <input type="range" name="eq5" id="eq5" min="0" max="48" value="24" step="1"
                    onchange="changeEq(this);" class="custom-range" data-band="5">&nbsp;1k&nbsp;hz

                <input type="range" name="eq6" id="eq6" min="0" max="48" value="24" step="1"
                    onchange="changeEq(this);" class="custom-range" data-band="6">&nbsp;2k&nbsp;hz

                <input type="range" name="eq7" id="eq7" min="0" max="48" value="24" step="1"
                    onchange="changeEq(this);" class="custom-range" data-band="7">&nbsp;4k&nbsp;hz

                <input type="range" name="eq8" id="eq8" min="0" max="48" value="24" step="1"
                    onchange="changeEq(this);" class="custom-range" data-band="8">&nbsp;8k&nbsp;hz

                <input type="range" name="eq9" id="eq9" min="0" max="48" value="24" step="1"
                    onchange="changeEq(this);" class="custom-range" data-band="9">&nbsp;16k&nbsp;hz

            </div>
        </div>
    </div>

    </div>
</body>

</html>
)=====";
