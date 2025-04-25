import React, { useState, useEffect } from 'react'
import { useNavigate, useParams } from 'react-router-dom'
import axios from 'axios'

function Update(){
    
    const {id} = useParams();
    const navigate = useNavigate();

    useEffect(()=> {
        axios.get('http://localhost:3001/read/'+id)
        .then(res => {
            console.log(res)
            setValues({...values, parking_name: res.data[0].parking_name, status: res.data[0].status})
        })
        .catch(err => console.log(err))
    }, [])
    
    const [values, setValues] = useState({
            parking_name: '',
            status: ''
        })
    
    const handleUpdate = (event) => {
        event.preventDefault();
        axios.put('http://localhost:3001/update/'+id, values)
        .then(res => {
            console.log(res)
            navigate('/')
        }).catch(err => console.log(err));
    }

    return (
        <div className='d-flex vh-100 bg-primary justify-content-center align-items-center'>
        <div className='w-50 bg-white rounded p-3'>
            <form onSubmit={handleUpdate}>
                <h2>Update Parking Space Name</h2>
                <div className='mb-2'>
                    <label htmlFor=''>Parking Name</label>
                    <input type="text" placeholder='Enter Name' className='form-control' value={values.parking_name}
                    onChange={e => setValues({...values, parking_name: e.target.value})}/>
                </div>
                <div className='mb-2'>
                    <label htmlFor=''>Parking Status</label>
                    <input type="text" placeholder='Edit Status' className='form-control' value={values.status}
                    onChange={e => setValues({...values, status: e.target.value})}/>
                </div>
                <button className='btn btn-success'>Update</button>
            </form>
        </div>
    </div>
    )
  }
  
  export default Update;