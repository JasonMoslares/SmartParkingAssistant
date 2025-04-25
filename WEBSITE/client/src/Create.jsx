import React, { useState } from 'react'
import axios from 'axios'
import { useNavigate } from 'react-router-dom'

function Create() {
    const [values, setValues] = useState({
        parking_name: ''
    })

    const navigate = useNavigate()

    const handleSubmit = (e) => {
        e.preventDefault();
        axios.post('http://localhost:3001/photosensor', values)
        .then(res => {
            console.log(res);
            navigate('/')
        })
        .catch(err => console.log(err))
    }
    return(
        <div className='d-flex vh-100 bg-primary justify-content-center align-items-center'>
            <div className='w-50 bg-white rounded p-3'>
                <form onSubmit={handleSubmit}>
                    <h2>Add Parking Space</h2>
                    <div className='mb-2'>
                        <label htmlFor=''>Parking Space Name</label>
                        <input type="text" placeholder='Enter Name' className='form-control' 
                        onChange={e => setValues({...values, parking_name: e.target.value})}/>
                    </div>
                    <button className='btn btn-success'>Submit</button>
                </form>
            </div>
        </div>
    )
}

export default Create
