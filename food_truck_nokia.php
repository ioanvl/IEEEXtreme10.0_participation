<?php
$_fp = fopen("php://stdin", "r");


$line=fgets($_fp);
$my_loc=str_getcsv($line);
$my_loc[0]=floatval($my_loc[0]*pi()/180);
$my_loc[1]=floatval($my_loc[1]*pi()/180);

$line=fgets($_fp);
$rad=floatval($line);

$line=fgets($_fp);

$now=time();

while(!feof($_fp)){

	$line=fgets($_fp);

	$ln=explode(",", $line);

	$ln[2]=floatval($ln[2]*pi()/180);
	$ln[1]=floatval($ln[1]*pi()/180);

	$d = 2 * 6378.137 * asin (sqrt (pow(sin(($my_loc[0] - $ln[1])/2), 2)) + (cos($my_loc[0]) * (cos($ln[1]) * (pow(sin(($my_loc[1] - $ln[2])/2), 2)))));


	if(isset($res["$ln[3]"]["time"])){
		$t=strtotime($ln[0], $now);
		if ($t>$res["$ln[3]"]["time"]){
			$res["$ln[3]"]["time"]=$t;
			$res["$ln[3]"]["dist"]=$d;
		}
	}
	else{
		$t=strtotime($ln[0], $now);
		$res["$ln[3]"]["time"]=$t;
		$res["$ln[3]"]["dist"]=$d;
	}
}

$out;

if(!empty($res)){
	ksort($res);
	foreach ($res as $key => $value) {
		if($value["dist"]<=$rad){
			$out=$out.trim($key).",";
		}
	}
}
print(rtrim($out, ","));


?>