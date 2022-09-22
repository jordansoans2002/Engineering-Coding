questions = [
  'From where do you get printouts',
  'Have you ever needed a printout but not been able to get it because it was too late at night?',
]
options = [
  ['Home', "Parent's workplace", "Shop"],
  ['Very often', 'Sometimes', 'Rarely', 'Never']
]
answers = []
qsNo = 0;
multi = false;

function loadQs(m) {
  if (m == 0 || qsNo > 0 && m == -1 || qsNo < questions.length-1 && m == 1)
    qsNo = qsNo + m;
  else
    return;
  $('#qs').text(questions[qsNo]);
  multi = false;
  for (i = 0; i < 4; i++) {
    if (i < options[qsNo].length){
			/* if(options[qsNo][i]==='other'){
				$('.options').eq(i).html("Other <input type='text' name='other' id='other' class=options>");//defective
			}else */
				$('.options').eq(i).text(options[qsNo][i]);
				$('.options').eq(i).show();
		}
    else
      $('.options').eq(i).hide();
  }
	$('.options').removeClass('selected');
	if(answers[qsNo]!=null)
		$('.options').eq(answers[qsNo]).addClass('selected');
}

function selectOption(option) {
  if (!multi)
    $(".options").removeClass("selected");
  $(".options").eq(option).toggleClass('selected');
  answers[qsNo] = option;
}
