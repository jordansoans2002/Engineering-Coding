//import React,{ Component } from 'react'
class JobCard extends React.Component{
	render(){
		return(
			<div type="button" class="card" data-bs-toggle='modal' data-bs-target="#login-modal">
      <div class="card-header">
        {this.props.jobrole}
      </div>

      <div class='flip-card card-body'>
        <div class='flip-card-inner'>
          
          <div class='flip-card-front'>
              {this.props.description}
          </div>

          <div class='flip-card-back'>
						Qualifications: {this.props.qualifications}<br></br>
						Exam duration: {this.props.duration}<br></br>
            Paper pattern: {this.props.pattern}
          </div>
        </div>
      </div>
    </div>
		);
	}
}
//export default JobCard

const root=ReactDOM.createRoot(document.getElementById('root'));
root.render(<>
	<JobCard jobrole='ut 1' description='Something will be written about this job role. The description will be allotted a max number of characters to fit within the card.' qualifications='Qualifications required' duration='1 hour' pattern='mcq'/>
					 <JobCard jobrole='Job Role' description='Something will be written about this job role. The description will be allotted a max number of characters to fit within the card.' qualifications='Qualifications required' duration='1 hour' pattern='mcq'/>
					 <JobCard jobrole='Job Role' description='Something will be written about this job role. The description will be allotted a max number of characters to fit within the card.' qualifications='Qualifications required' duration='1 hour' pattern='mcq'/>
		</>);
